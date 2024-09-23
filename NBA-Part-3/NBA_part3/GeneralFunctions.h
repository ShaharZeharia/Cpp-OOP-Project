#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include <iostream>
using namespace std;
#include <string>

int getIntWithPrompt(const string& message);
float getFloatWithPrompt(const string& message);
int getEnumSelection(const string& message, const string types[], const int numOfTypes);
string getStrExactName(const string& msg);
void cleanBuffer();

#endif