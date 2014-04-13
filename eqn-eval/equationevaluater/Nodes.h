#ifndef NODES
#define NODES

#include "Include.h"

//Node Structure is based off of: http://math.hws.edu/eck/cs225/s03/binary_trees/

class BaseNode
{
public:
	virtual int value() = 0;
	virtual std::string print() = NULL;
};

class VarNode : public BaseNode
{
public:

	int intCoEfficient;
//	float fltCoEfficient;
	int intVarValue;
	std::string varName;

	VarNode()
	{
		intCoEfficient = 1;
//		fltCoEfficient = 1;
		intVarValue = 1;
	}

	std::string print()
	{
		std::string strPrint;
		std::stringstream ss;
		ss << intCoEfficient;
		ss << varName;
		ss >> strPrint;
		return strPrint;
	}

	int value()
	{
		return intCoEfficient * intVarValue;
	}
};

class OpNode : public BaseNode
{
	BaseNode *nodeLeft; //The left node
	BaseNode *nodeRight; //The right node

	public:

	char charOp; //The operator type

	std::string print()
	{
		std::string strPrint;
		std::stringstream ss;
		ss << charOp;
		ss >> strPrint;
		return strPrint;
	}


	int value()
	{
		int leftValue = nodeLeft->value();
		int rightValue = nodeRight->value();
		switch( charOp )
		{
		case '/': return leftValue / rightValue;
		case '*': return leftValue * rightValue;
		case '-': return leftValue - rightValue;
		case '+': return leftValue + rightValue;
		case '^': return pow(leftValue, rightValue);
		}
	}
};

class BracketNode : public BaseNode
{
	public:

	Equation contents;

	std::string print()
	{
		std::string strPrint;
		std::stringstream ss;
		std::vector<BaseNode*>::iterator iter;
		for(iter = contents.vtrNodeEquation.begin(); iter != contents.vtrNodeEquation.end(); ++iter)
		{
			ss << (*iter)->print();
			ss << ' ';
		}
		ss >> strPrint;
		return strPrint;
	}

	int value()
	{
		return 0;
	}
};

#endif