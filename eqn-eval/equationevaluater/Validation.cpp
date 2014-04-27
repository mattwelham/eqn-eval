#include "Main.h"
using namespace std;

bool validateEquation(Equation equation)
{
	if(equation.eqnLength < 1)
	{
		return false;
	}
	else if(equation.eqnLength == 1 && equation.vtrNodeEquation.at(0)->type == OPERATOR)
	{
		return false;
	}
	else if(validateVarOrder == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool validateVarOrder(Equation equation)
{
	vector<BaseNode*>::iterator iter;
	for(iter = equation.vtrNodeEquation.begin(); iter != equation.vtrNodeEquation.end(); ++iter)
	{
		if((*iter)->type == VARIABLE && (*(iter+1))->type == VARIABLE)
		{
			return false;
		}
	}
	return true;
}