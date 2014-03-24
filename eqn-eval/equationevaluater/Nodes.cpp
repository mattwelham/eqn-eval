#include "Main.h"
using namespace std;

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
	string varName;

VarNode()
{
	intCoEfficient = 1;
	fltCoEfficient = 1;
}
};

class ConstNode : public BaseNode
{
	int constNum; //The constant contained by the node
public:
	int	value()
	{
		return constNum;
	}
};

class OpNode : public BaseNode
{
	char charOp; //The operator type
	BaseNode *nodeLeft; //The left node
	BaseNode *nodeRight; //The right node

	public:

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