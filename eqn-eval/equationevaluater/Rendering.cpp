#include "Main.h"
 using namespace std;



 void renderExpressionTree (SDL_Renderer* renderer, int scrWidth, int scrHeight, ExpressionTree expTree, vector<VarNode*> indVar, int* range)
 {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	float horizontalAspect = scrWidth / (range[1] - range[0]);

	vector<VarNode*>::iterator iter;
	for(iter = indVar.begin(); iter != indVar.end(); ++iter)
	{
		(*iter)->intVarValue = range[0];
	}
	int x;
	int y;
	int x2 = range[0] ;
	int y2 = scrHeight - expTree.value();

	for( int i = range[0]; i < range[1]; i++)
	{
		x = x2;
		y = y2;
		for(iter = indVar.begin(); iter != indVar.end(); ++iter)
		 {
			 (*iter)->intVarValue = i+1;
		 }
		x2 = (i+1)*horizontalAspect;
		y2 = scrHeight - expTree.value();

		SDL_RenderDrawLine(renderer, x, y, x2, y2);
	}

 }