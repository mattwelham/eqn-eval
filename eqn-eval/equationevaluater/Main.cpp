#include "Main.h"
using namespace std;

int main(int argc, char* args[])
{
	bool quitPrompted = false;
	cout << "Options" << endl << "1. Graph Equation" << endl << "2. Help" << endl << "3. Quit" << endl;
	
	while(quitPrompted == false)
	{
		string menuInput;
		cout << endl << "> ";
		getline(cin, menuInput);
		if(menuInput == "1")
			graphMain();
		else if(menuInput == "2")
			cout << "Accepted Operators: +, - , *, /, ^";
		else if(menuInput == "3")
			quitPrompted = true;

	}
 
    return 0;
}