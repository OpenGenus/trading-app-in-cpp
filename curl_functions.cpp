#include "curl_function.h"
#include <iostream>
#include <curl/curl.h>
#include <string>
using namespace std;


// Callback function for cURL to handle the response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

string get_price(const string& ticker_symbol, const string& api) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Failed to initialize cURL." << endl;
        return "";
    }

    // Set up the URL
    string url = "https://api.twelvedata.com/price?symbol=" + ticker_symbol + "&apikey=" + api;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Create a string to store the JSON response
    string jsonResponse;

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &jsonResponse);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "cURL request failed: " << curl_easy_strerror(res) << endl;
        return "";
    }

    // Clean up cURL
    curl_easy_cleanup(curl);

    // Parse the JSON data using JsonCpp
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value root;
    string errors;
    if (!reader->parse(jsonResponse.c_str(), jsonResponse.c_str() + jsonResponse.size(), &root, &errors)) {
        cerr << "Failed to parse JSON: " << errors << endl;
        delete reader;
        return "";
    }
    delete reader;

    // Extract and return the price
    string price = root["price"].asString();
    return price;
}

Json::Value get_stock_quote(const string& ticker_symbol, const string& api) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Failed to initialize cURL." << endl;
        return Json::Value(); // Return an empty JSON value on error
    }

    // Set up the URL
    string url = "https://api.twelvedata.com/quote?symbol=" + ticker_symbol + "&apikey=" + api;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Create a string to store the JSON response
    string jsonResponse;

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &jsonResponse);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "cURL request failed: " << curl_easy_strerror(res) << endl;
        return Json::Value(); // Return an empty JSON value on error
    }

    // Clean up cURL
    curl_easy_cleanup(curl);

    // Parse the JSON data using JsonCpp
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value root;
    string errors;
    if (!reader->parse(jsonResponse.c_str(), jsonResponse.c_str() + jsonResponse.size(), &root, &errors)) {
        cerr << "Failed to parse JSON: " << errors << endl;
        delete reader;
        return Json::Value(); // Return an empty JSON value on error
    }
    delete reader;

    return root;
}
