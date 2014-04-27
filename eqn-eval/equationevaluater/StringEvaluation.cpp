#include "Main.h"
using namespace std;



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
	Equation* pEquation = &equation;
	vector<string>::iterator iter;

	//iterate through the elements in the string equation vector
	for(iter = vtrStrEquation.begin(); iter != vtrStrEquation.end(); ++iter)
	{

		if( isOperator( *iter ))
		{
		CreateOpNode(pEquation, *iter);
		}

		else if( isVariable( *iter ))
		{
		CreateVarNode(pEquation, *iter);
		}

		else if( isOpenBracket( *iter ))
		{
		BracketNode* bracket = new BracketNode;
		vector<string> vtrStrBracketEquation(iter, vtrStrEquation.end());																				
		bracket->contents = identifyBracketContents( vtrStrBracketEquation );				//identify and create seperate equation for bracket contents
		equation.vtrNodeEquation.push_back(bracket);										//add reference to current bracket node to the equation
		equation.vtrBracketStore.push_back(*bracket);										//add current bracket node object to vector so it doesn't go out of scope
		iter += (bracket->contents.eqnLength + 1);
		}
	}
	equation.eqnLength = equation.vtrNodeEquation.size();
	return equation;
}

void deleteNodes(Equation equation)
{
	for(vector<BaseNode*>::iterator it = equation.vtrNodeEquation.begin(); it != equation.vtrNodeEquation.end(); it++) 
	{
    delete *it;
	}
}