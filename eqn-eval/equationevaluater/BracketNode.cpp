#include "Main.h"
using namespace std;

BracketNode::BracketNode()
{
	type = BRACKET;
}

string BracketNode::print()
{
	string strPrint;
	stringstream ss;
	vector<BaseNode*>::iterator iter;
	for(iter = contents.vtrNodeEquation.begin(); iter != contents.vtrNodeEquation.end(); ++iter)
	{
		ss << (*iter)->print();
		ss << ' ';
	}
	ss >> strPrint;
	return strPrint;
}

int BracketNode::value()
{
	ExpressionTree BracketTree;
	BracketTree.createTree(contents);

	return BracketTree.value();
}