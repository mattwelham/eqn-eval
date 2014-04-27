#include "Main.h"
using namespace std;

string inputStrEQN()
{
	string strEquation;
	cout << "Enter your equation: ";
	getline(cin, strEquation);
	return strEquation;
}

vector<VarNode*> inputConstantValues( Equation equation )
{
	vector<VarNode*> returnVector;
	int varValue;
	string strInput;
	if(equation.vtrStrVarList.size() > 1)
	{
		cout << "If the following variable is a coefficient, please enter a value for it. Otherwise leave the field blank and press enter:" << endl;
		vector<string>::iterator vtrStrIterator;
		for( vtrStrIterator = equation.vtrStrVarList.begin(); vtrStrIterator != equation.vtrStrVarList.end(); ++vtrStrIterator)
		{
			cout << endl << *vtrStrIterator << ": ";
			cin >> strInput;
			if( isdigit(strInput.c_str()[0]) != false)
			{
				varValue = atoi(strInput.c_str());
				vector<VarNode*>::iterator vtrVarIterator;
				int iterPos = vtrStrIterator - equation.vtrStrVarList.begin();
				for(vtrVarIterator = equation.vtrVtrVarListStore.at(iterPos).begin(); vtrVarIterator != equation.vtrVtrVarListStore.at(iterPos).end(); ++vtrVarIterator)
				{
					(*vtrVarIterator)->intVarValue = varValue;
				}
				cout << endl << *vtrStrIterator << " is a coefficient with value " << varValue << ".";
			}
			else
			{
				returnVector = equation.vtrVtrVarListStore.at(vtrStrIterator - equation.vtrStrVarList.begin());
				cout << endl << *vtrStrIterator << " is an unknown.";
			}

		}
	}
	else if(equation.vtrStrVarList.size() == 1)
	{
		returnVector = equation.vtrVtrVarListStore.at(0);
	}
	return returnVector;
}

int* inputRange()
{
	int* range = new int[2];
	string inputtemp;
	cout << "Enter the start of the range: ";
	cin >> inputtemp;
	if( isdigit( inputtemp.c_str()[0]) != false )
	{
		range[0] = atoi(inputtemp.c_str());
	}
	cout << "Enter the end of the range: ";
	cin >> inputtemp;
	if( isdigit( inputtemp.c_str()[0]) != false )
	{
		range[1] = atoi(inputtemp.c_str());
	}
	return &range[0];
}