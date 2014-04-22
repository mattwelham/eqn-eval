#include "Main.h"
using namespace std;



int convertCoEfficient( string element )
{
	int CoEfficient = 1;
	if( isdigit(element.at(0)) )
		{
			//convert any numbers preceding the variable into the co-efficient
			CoEfficient = atoi(element.c_str());
		}
	else if( element.at(0) == '-' && element.size() != 1)
	{
		CoEfficient = atoi(element.c_str()+1)*(-1);
	}

	return CoEfficient;
}

string convertVariableName( string element )
{
	string variableName;
	//loop through characters in current vector entry
	for(unsigned int i = 0; i < element.size(); i++)
	{
		if( isalpha(element.at(i)))
		{
			//add current character to variable name
			variableName += element.at(i);
		}
	}

	return variableName;
}

Equation identifyBracketContents( vector<string> vtrStrEquation)
{
		vector<string>::iterator iter;
		Equation bracketEquation;
		int bracketIndentLevel = 0;
		for(iter = vtrStrEquation.begin() + 1; iter != vtrStrEquation.end(); ++iter)
		{

			if( isOpenBracket( *iter ))
			{
				bracketIndentLevel++;
			}

			else if( isCloseBracket( *iter ))
			{
				if(bracketIndentLevel < 1)
				{
					vector<string> vtrStrBracketEquation(vtrStrEquation.begin() + 1, iter);
					bracketEquation = evalVtrStrEquation(vtrStrBracketEquation);
					return bracketEquation;
				}

				else
				{
					bracketIndentLevel--;
				}
			}
		}

}