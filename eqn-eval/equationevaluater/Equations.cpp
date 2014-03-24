#include "Equations.h"
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

vector<string> &split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) 
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

class variable
{
public:

	int intCoEfficient;
	float fltCoEfficient;
	string varName;

variable::variable()
{
	intCoEfficient = 1;
	fltCoEfficient = 1;
}
};



void parseEquation(string strEquation)
{

	vector<string> vtrStrEquation;
	//split raw string equation into elements in a string vector with a delimiter of ' '
	vtrStrEquation = split(strEquation, ' ');

	vector<variable> vtrVarEquation;
	vector<string>::const_iterator iter;

	//iterate through the elements in the string equation vector
	for(iter = vtrStrEquation.begin(); iter != vtrStrEquation.end(); ++iter)
	{
		variable var;
		var.intCoEfficient = convertCoEfficient( *iter );
		var.varName = convertVariableName( *iter );

		cout << var.intCoEfficient << ' ';
		cout << var.varName << "\n";

		//add current co-efficient and variable to the equation
		vtrVarEquation.push_back(var);
	}
}

