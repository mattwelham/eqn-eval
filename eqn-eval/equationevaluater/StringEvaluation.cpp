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

	vector<unique_ptr<BaseNode>> vtrNodeEquation;

	//iterate through the elements in the string equation vector
	for(iter = vtrStrEquation.begin(); iter != vtrStrEquation.end(); ++iter)
	{
		if( isVariable( *iter ))
		{
		unique_ptr<VarNode> var(new VarNode);
		var->intCoEfficient = convertCoEfficient( *iter );
		var->varName = convertVariableName( *iter );
		vtrNodeEquation.push_back(var); //THIS NEEDS FIXING
		}

		cout << var.intCoEfficient << ' ';
		cout << var.varName << "\n";

		//add current co-efficient and variable to the equation
		vtrVarEquation.push_back(var);
	}
}

