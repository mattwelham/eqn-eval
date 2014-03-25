#include "Main.h"
using namespace std;

// ----------TODO-----------
// - Fix Co-Efficent being printed multiple times ( + symbol has a co-effecient?)
// ----------TODO-----------



string inputEQN()
{
	string strEquation;
	cout << "Enter your equation: ";
	getline(cin, strEquation);
	return strEquation;
}

void evalStrEquation(string strEquation)
{

	vector<string> vtrStrEquation;
	//split raw string equation into elements in a string vector with a delimiter of ' '
	vtrStrEquation = split(strEquation, ' ');

	vector<string>::const_iterator iter;

	//a vector that contains pointers to all nodes in the equation
	vector<BaseNode*> vtrNodeEquation;

	//a vector that stores all variable nodes
	vector<VarNode> vtrVarStore;

	//iterate through the elements in the string equation vector
	for(iter = vtrStrEquation.begin(); iter != vtrStrEquation.end(); ++iter)
	{

		if( isOperator( *iter ))
		{
		OpNode oper;
		OpNode* poper = &oper;
		oper.charOp = iter->at(0);
		//add current operator to the equation
		vtrNodeEquation.push_back(poper);
		}

		else if( isVariable( *iter ))
		{
		//THIS NEEDS TO BE DELETED
		VarNode* pVar = new VarNode;
		pVar->intCoEfficient = convertCoEfficient( *iter );
		pVar->varName = convertVariableName( *iter );
		//add current co-efficient and variable to the equation
		vtrNodeEquation.push_back(pVar);
		vtrVarStore.push_back(*pVar);
		}
		
	}
	for(vector<BaseNode*>::iterator it = vtrNodeEquation.begin(); it != vtrNodeEquation.end(); it++) 
	{
	//CAUSES A DEBUG ASSERTION FAILURE?
    delete *it;
	}
}

