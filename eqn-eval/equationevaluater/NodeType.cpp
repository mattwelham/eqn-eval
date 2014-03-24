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