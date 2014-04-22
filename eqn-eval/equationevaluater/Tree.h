#ifndef NODES
#define NODES

#define _OPERATORS_ 5

#include "Include.h"

//Node Structure is based off of: http://math.hws.edu/eck/cs225/s03/binary_trees/

enum NodeType {VARIABLE, OPERATOR, BRACKET};

class BaseNode
{
public:

	NodeType type;
	virtual int value() = 0;
	virtual std::string print() = NULL;

};

class VarNode : public BaseNode
//defined in VarNode.cpp
{
public:

	int intCoEfficient;
	int intVarValue;
	std::string varName;

	VarNode();

	std::string print();
	int value();

};

class OpNode : public BaseNode
//defined in OpNode.cpp
{
	public:

	BaseNode* leftNode; //The left node
	BaseNode* rightNode; //The right node
	OpNode* parentNode;

	char charOp; //The operator type
	Equation leftEqn;
	Equation rightEqn;

	OpNode();

	std::string print();
	int value();
};

class BracketNode : public BaseNode
//defined in BracketNode.cpp
{
	public:

	Equation contents;

	BracketNode();

	std::string print();
	int value();

};


class ExpressionTree
{
public:
	ExpressionTree();
//	~ExpressionTree();

	void createTree( Equation equation );
//	void destroyTree();

	int value();

	OpNode* root;

	void evalBranch( OpNode* stemNode );
	OpNode* createBranch(Equation equation);
	BaseNode* evalEqnPriority( Equation equation );
//private:


};
#endif