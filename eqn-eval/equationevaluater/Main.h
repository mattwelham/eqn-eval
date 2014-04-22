#ifndef MAIN
#define MAIN

#include "Include.h"
#include "Structs.h"
#include "Tree.h"

//stringevaluation.cpp
std::string inputEQN();
std::vector<std::string> createVtrStrEquation(std::string strEquation);
Equation evalVtrStrEquation(std::vector<std::string> vtrStrEquation);
void deleteNodes(Equation equation);

//split.cpp
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

// stringequationconversion.cpp
int convertCoEfficient( std::string element );
std::string convertVariableName( std::string element );
Equation identifyBracketContents( std::vector<std::string> vtrStrEquation);

// nodetype.cpp
bool isVariable( std::string element );
bool isOperator( std::string element );
bool isOpenBracket( std::string element );
bool isCloseBracket( std::string element );

#endif