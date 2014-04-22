#include "Main.h"
using namespace std;

OpNode::OpNode()
{
	type = OPERATOR;
	leftNode = nullptr;
	rightNode = nullptr;
	parentNode = nullptr;
}

string OpNode::print()
{
	string strPrint;
	stringstream ss;
	ss << charOp;
	ss >> strPrint;
	return strPrint;
}

int OpNode::value()
{
	int leftValue = leftNode->value();
	int rightValue = rightNode->value();
	switch( charOp )
	{
	case '/': return leftValue / rightValue;
	case '*': return leftValue * rightValue;
	case '-': return leftValue - rightValue;
	case '+': return leftValue + rightValue;
	case '^': return pow(leftValue, rightValue);
	}
}