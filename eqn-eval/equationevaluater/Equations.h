#pragma once;

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//equations.cpp

string inputEQN();
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
void parseEquation(string strEquation);

// stringequationconversion.cpp
int convertCoEfficient( string element );
string convertVariableName( string element );
