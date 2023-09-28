#include "functions.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void ProfitLoss(float open, float close, std::string name) {
    float percentage_change = ((close - open) / open) * 100;

    if (percentage_change > 0) {
        cout << "\nThe " + name + " stocks is in profit of " << percentage_change << "%\n";
    } else if (percentage_change < 0) {
        cout << "\nThe " + name + " stocks is in loss of " << percentage_change << "%\n";
    } else {
        cout << "\nThe " + name + " stocks is in a neutral state of " << percentage_change << "%\n";
    }
}

void wantTransact(string ans, int amount, float price) {
    cout << "Enter the amount of stock of buying selling limit: ";
    cin >> amount;
    cout << "\nWant to know the cost of buying or selling stock? Enter Y for yes and N for no\n";
    cout << "Your Response: ";
    cin >> ans;
    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    if (ans == "Y") {
        cout << "\nThe stock cost: " << amount * price << "\n";
    } else if (ans == "N") {
        cout << "\nOKAY\n\n";
    } else {
        cout << "\nInvalid Choice\n";
    }
}

void print_data(string name, string exchange, string currency, float open, float high, float low, float close, float volume, float change, float price) {
    cout << "\nGenerating Data....\n\n";
    cout <<
        "name: " << name << "\n" <<
        "exchange: " << exchange << "\n" <<
        "currency:" << currency << "\n" <<
        "Open price: " << open << "\n" <<
        "High price: " << high << "\n" <<
        "Low price: " << low << "\n" <<
        "Close price: " << close << "\n" <<
        "Volume:" << volume << "\n" <<
        "Change: " << change << "\n" <<
        "Current Price: " << price << "\n";
}

void Sendsignal(float price, float high, float low, string ans, int amount){
    if(price <= low){
        cout << "Sending Buying signal\n\n";
        wantTransact(ans, amount, price);
    }
    else if(price >= high){
        cout << "Sending Selling signal\n\n";
        wantTransact(ans, amount, price);
    }
    else{
        cout << "Not suitable for buying and selling\nHappy Trading!!!\n\n";
    }
}
