#include "Include.h"
using namespace std;

//Node Structure is based off of: http://math.hws.edu/eck/cs225/s03/binary_trees/

class BaseNode
{
public:
	virtual int value() = 0;
};

class VarNode : public BaseNode
{
public:

	int intCoEfficient;
	float fltCoEfficient;
	int intVarValue;
	string varName;

	VarNode()
	{
		intCoEfficient = 1;
		fltCoEfficient = 1;
		intVarValue = 1;
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