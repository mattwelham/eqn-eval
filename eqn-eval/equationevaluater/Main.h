#ifndef STRUCTS
#define STRUCTS

#include "Include.h"
#include "Structures.h"
#include "Nodes.h"

//stringevaluation.cpp
struct Equation;
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