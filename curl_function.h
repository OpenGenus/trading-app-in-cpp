#ifndef CURL_FUNCTIONS_H
#define CURL_FUNCTIONS_H

#include <string>
#include <jsoncpp/json/json.h>
using namespace std;

string get_price(const string& ticker_symbol, const string& api);
Json::Value get_stock_quote(const string& ticker_symbol, const string& api);

#endif // CURL_FUNCTIONS_H
