#ifndef STRUCTS
#define STRUCTS

#include "Include.h"

//dependencies
class BaseNode;
class VarNode;
class OpNode;
class BracketNode;

struct Equation
{
	int eqnLength;								//length of the equation

	std::vector<std::string> vtrStrEquation;	//a vector of string elements

	std::vector<VarNode> vtrVarStore;			//a vector that stores all variable nodes
	std::vector<OpNode> vtrOpStore;				//a vector that stores all operator nodes
	std::vector<BracketNode> vtrBracketStore;	//a vector that stores all bracket nodes

	std::vector<BaseNode*> vtrNodeEquation;		//a vector that contains pointers to all nodes in the equation
};


#endif