#include "Main.h"
using namespace std;

vector<string> &splitexclude(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> splitexclude(const string &s, char delim) 
{
    vector<string> elems;
    splitexclude(s, delim, elems);
    return elems;
}

vector<string> &splitinclude(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
	string strdelim(1,delim);
    while (getline(ss, item, delim))
	{
		if(item != "")
		{
        elems.push_back(item);
		}
		elems.push_back(strdelim);
    }
	if(elems.size() > 2 || elems.at(0) == s)
	{
	elems.pop_back();
	}
    return elems;
}

vector<string> splitinclude(const string &s, char delim) 
{
    vector<string> elems;
    splitinclude(s, delim, elems);
    return elems;
}