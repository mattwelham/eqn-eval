#include "Main.h"
using namespace std;

string inputEQN()
{
	string strEquation;
	cout << "Enter your equation: ";
	getline(cin, strEquation);
	return strEquation;
}

vector<string> createVtrStrEquation(string strEquation)
{
	vector<string> vtrStrEquation;
	//split raw string equation into elements in a string vector with a delimiter of ' '
	vtrStrEquation = split(strEquation, ' ');
	return vtrStrEquation;
}

Equation evalVtrStrEquation(vector<string> vtrStrEquation)
{
	Equation equation;
	vector<string>::iterator iter;

	//iterate through the elements in the string equation vector
	for(iter = vtrStrEquation.begin(); iter != vtrStrEquation.end(); ++iter)
	{

		if( isOperator( *iter ))
		{
		OpNode* oper = new OpNode;
		oper->charOp = iter->at(0);
		equation.vtrNodeEquation.push_back(oper);											//add reference to current operator to the equation
		equation.vtrOpStore.push_back(*oper);												//add current operator node object to vector so it doesn't go out of scope
		}

		else if( isVariable( *iter ))
		{
		VarNode* var = new VarNode;
		var->intCoEfficient = convertCoEfficient( *iter );
		var->varName = convertVariableName( *iter );
		equation.vtrNodeEquation.push_back(var);											//add reference to current co-efficient and variable to the equation
		equation.vtrVarStore.push_back(*var);												//add current variable node object to vector so it doesn't go out of scope
		}
		
		else if( isOpenBracket( *iter ))
		{
		BracketNode* bracket = new BracketNode;
		vector<string> vtrStrBracketEquation(iter, vtrStrEquation.end());																				
		bracket->contents = identifyBracketContents( vtrStrBracketEquation );				//idenify and create seperate equation for bracket contents
		equation.vtrNodeEquation.push_back(bracket);										//add reference to current bracket node to the equation
		equation.vtrBracketStore.push_back(*bracket);										//add current bracket node object to vector so it doesn't go out of scope
		iter += (bracket->contents.eqnLength + 2);
		}
	}
	return equation;
}

void deleteNodes(Equation equation)
{
	for(vector<BaseNode*>::iterator it = equation.vtrNodeEquation.begin(); it != equation.vtrNodeEquation.end(); it++) 
	{
    delete *it;
	}
}