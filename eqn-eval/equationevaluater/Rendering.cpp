#include "Main.h"
 using namespace std;



 void renderExpressionTree (SDL_Renderer* renderer, int scrWidth, int scrHeight, ExpressionTree expTree, vector<VarNode*> indVar, int* range)
 {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	float horizontalAspect = scrWidth / (range[1] - range[0]);
	float verticalAspect = scrHeight / (range[1] - range[0]);
	if(indVar.size() > 0)
	{
	vector<VarNode*>::iterator iter;
	for(iter = indVar.begin(); iter != indVar.end(); ++iter)
	{
		(*iter)->intVarValue = range[0];
	}
	int x;
	int y;
	int x2 = range[0]*horizontalAspect;
	int y2 = scrHeight - (expTree.value()*verticalAspect);

	for( int i = range[0]; i < range[1]; i++)
	{
		x = x2;
		y = y2;
		for(iter = indVar.begin(); iter != indVar.end(); ++iter)
		 {
			 (*iter)->intVarValue = i;
		 }
		x2 = i*horizontalAspect;
		y2 = scrHeight - (expTree.value()*verticalAspect);

		SDL_RenderDrawLine(renderer, x, y, x2, y2);
	}
	}
	else
	{
	int x = range[0];
	int y = scrHeight - (expTree.value()*verticalAspect);
	int x2 = range[1]*horizontalAspect;
	int y2 = scrHeight - (expTree.value()*verticalAspect);

	SDL_RenderDrawLine(renderer, x, y, x2, y2);
	}
 }