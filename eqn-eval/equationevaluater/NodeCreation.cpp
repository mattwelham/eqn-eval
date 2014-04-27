#include "Main.h"
using namespace std;

void CreateOpNode(Equation* pEquation, string opString)
{
		OpNode* oper = new OpNode;
		oper->charOp = opString.at(0);
		pEquation->vtrNodeEquation.push_back(oper);											//add reference to current operator to the equation
		pEquation->vtrOpStore.push_back(*oper);												//add current operator node object to vector so it doesn't go out of scope
}

void CreateVarNode(Equation* pEquation, string varString)
{
	VarNode* var = new VarNode;
	var->intCoEfficient = convertCoEfficient( varString );
	var->varName = convertVariableName( varString );
	pEquation->vtrNodeEquation.push_back(var);											//add reference to current co-efficient and variable to the equation
	pEquation->vtrVarStore.push_back(*var);												//add current variable node object to vector so it doesn't go out of scope

	bool isInVarList = false;
	int namePosition;
	vector<string>::iterator varNameIterator;

	for(varNameIterator = pEquation->vtrStrVarList.begin(); varNameIterator != pEquation->vtrStrVarList.end(); ++varNameIterator)
	{
		if(var->varName == *varNameIterator || var->varName == "")
		{
			isInVarList = true;
			namePosition = varNameIterator - pEquation->vtrStrVarList.begin();
		}
	}

	if( isInVarList == false && var->varName != "")
	{
		pEquation->vtrStrVarList.push_back(var->varName);
		vector<VarNode*> newVarListStore;
		newVarListStore.push_back(var);
		pEquation->vtrVtrVarListStore.push_back(newVarListStore);	
	}

	else
	{
		if(var->varName != "" )
		{
		pEquation->vtrVtrVarListStore.at(namePosition).push_back(var);
		}
	}

}