#include "Main.h"
using namespace std;

//TODO: write a function to evaluate tree value

ExpressionTree::ExpressionTree()
{
	root = nullptr;
}

void ExpressionTree::createTree( Equation equation )
{
	root = createBranch(equation);
	if(root != false)
	{
	OpNode* rootOpPtr = static_cast<OpNode*>(root);
	evalBranch( rootOpPtr );
	}
	else
	{
		root = equation.vtrNodeEquation.at(0);
	}
}


void ExpressionTree::evalBranch( OpNode* stemNode )
{
	OpNode* NextNode;

	if(stemNode->leftNode == nullptr)
	{
		OpNode* leftNodeTemp = createBranch(stemNode->leftEqn);
		if(leftNodeTemp != false)
		{
		stemNode->leftNode = leftNodeTemp;
		leftNodeTemp->parentNode = stemNode;
		NextNode = leftNodeTemp;
		}
		else
		{
		stemNode->leftNode = stemNode->leftEqn.vtrNodeEquation.at(0);
		NextNode = stemNode;
		}
	}
	else if(stemNode->rightNode == nullptr)
	{
		OpNode* rightNodeTemp = createBranch(stemNode->rightEqn);
		if(rightNodeTemp != false)
		{
		stemNode->rightNode = rightNodeTemp;
		rightNodeTemp->parentNode = stemNode;
		NextNode = rightNodeTemp;
		}
		else
		{
		stemNode->rightNode = stemNode->rightEqn.vtrNodeEquation.at(0);
		NextNode = stemNode;
		}
	}
	else if(stemNode->parentNode == nullptr)
	{
		return;
	}
	else
	{
	NextNode = stemNode->parentNode;
	}

	evalBranch(NextNode);
}

OpNode* ExpressionTree::createBranch(Equation equation)
	//Determines where the current equation should be split into two equations
{
	if(equation.eqnLength > 1)
	{
		BaseNode* priorityNode;
		priorityNode = evalEqnPriority(equation);
		vector<BaseNode*>::iterator iter;
		for(iter = equation.vtrNodeEquation.begin(); iter != equation.vtrNodeEquation.end(); ++iter)
		{
			if( *iter == priorityNode )
			{
			OpNode* NodePtr = static_cast<OpNode*>(priorityNode);

			vector<BaseNode*> leftNodeEquation(equation.vtrNodeEquation.begin(), iter);
			vector<BaseNode*> rightNodeEquation(iter + 1, equation.vtrNodeEquation.end());
			NodePtr->leftEqn.vtrNodeEquation = leftNodeEquation;
			NodePtr->leftEqn.eqnLength = leftNodeEquation.size();
			NodePtr->rightEqn.vtrNodeEquation = rightNodeEquation;
			NodePtr->rightEqn.eqnLength = rightNodeEquation.size();
			return NodePtr;
			}
		}
	}
	else
	{
		//if the only node is a variable return false
		if(	equation.vtrNodeEquation.at(0)->type == VARIABLE || equation.vtrNodeEquation.at(0)->type == BRACKET )
		{
		return false;
		}
	}
}


BaseNode* ExpressionTree::evalEqnPriority( Equation equation )
	//Determines the operator with the highest priority in an equation
{

	char opPriorities[_OPERATORS_] = {'^', '/', '*', '+', '-'};
	BaseNode* priorityNode;		//Highest priority node in equation
	int priorityOperator = -1;
	vector<BaseNode*>::iterator iter;
	for(iter = equation.vtrNodeEquation.begin(); iter != equation.vtrNodeEquation.end(); ++iter)
	{
		if((*iter)->type == OPERATOR)
		{
			OpNode* opPtr = static_cast<OpNode*>(*iter);
			for(int i = 0; i < _OPERATORS_; i++)
			{
				if( opPtr->charOp == opPriorities[i])
				{
					if( (i > priorityOperator) || (priorityOperator == -1))
					{
						priorityOperator = i;
						priorityNode = *iter;
					}
				}

			}
		}
	}

	return priorityNode;
}

int ExpressionTree::value()
{
	return root->value();
}