#ifndef MAIN
#define MAIN

#include "Include.h"
#include "Structs.h"
#include "Tree.h"

//input.cpp
std::string inputStrEQN();
std::vector<VarNode*> inputConstantValues( Equation equation );
int* inputRange();

//stringevaluation.cpp
std::vector<std::string> createVtrStrEquation(std::string strEquation);
Equation evalVtrStrEquation(std::vector<std::string> vtrStrEquation);
void deleteNodes(Equation equation);

//split.cpp
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

//stringequationconversion.cpp
int convertCoEfficient( std::string element );
std::string convertVariableName( std::string element );
Equation identifyBracketContents( std::vector<std::string> vtrStrEquation);

//nodeidentification.cpp
bool isVariable( std::string element );
bool isOperator( std::string element );
bool isOpenBracket( std::string element );
bool isCloseBracket( std::string element );

//nodecreation.cpp
void CreateOpNode(Equation* pEquation, std::string opString);
void CreateVarNode(Equation* pEquation, std::string varString);

//rendering
 void renderExpressionTree (SDL_Renderer* renderer, int scrWidth, int scrHeight, ExpressionTree expTree, std::vector<VarNode*> indVar, int* range);

#endif