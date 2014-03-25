#include "Include.h"
#include "Nodes.h"

//equations.cpp
string inputEQN();
void evalStrEquation(string strEquation);

//split.cpp
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);

// stringequationconversion.cpp
int convertCoEfficient( string element );
string convertVariableName( string element );

// nodetype.cpp
bool isVariable( string element );
bool isOperator( string element );