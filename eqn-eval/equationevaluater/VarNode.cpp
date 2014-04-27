#include "Main.h"
using namespace std;

VarNode::VarNode()
{
	type = VARIABLE;
	intCoEfficient = 1;
	intVarValue = 1;
}

string VarNode::print()
{
	string strPrint;
	stringstream ss;
	ss << intCoEfficient;
	ss << varName;
	ss >> strPrint;
	return strPrint;
}

int VarNode::value()
{
	return intCoEfficient * intVarValue;
}