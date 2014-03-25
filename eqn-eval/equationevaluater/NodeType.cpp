#include "Main.h"
using namespace std;

bool isVariable( string element )
{
	for(int i = 0; i < element.length(); i++)
	{
		if( isalnum(element.at(i)) == false && element.at(i) != '-')
		{
			return false;
		}
	}
	return true;
}

bool isOperator( string element )
{
	if( element.size() == 1)
	{
		switch(element.at(0))
		{
		case '/':
		case '*':
		case '-':
		case '+':
		case '^':
			return true;
		}
	}

	return false;
}