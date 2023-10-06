#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <jsoncpp/json/json.h>
using namespace std;
void ProfitLoss(float open, float close, string name);
void wantTransact(string ans, int amount, float price);
void print_data(string name, string exchange, string currency, float open, float high, float low, float close, float volume, float change, float price);
void Sendsignal(float price, float high, float low, string ans, int amount);
#endif // FUNCTIONS_H
