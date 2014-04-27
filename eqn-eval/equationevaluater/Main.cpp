#include "Main.h"
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[])
{
	vector<string> vtrStrEquation = createVtrStrEquation((inputStrEQN()));
	int* range = inputRange();
	Equation equation;
	equation = evalVtrStrEquation(vtrStrEquation);
//	deleteNodes(equation);
	ExpressionTree eqnTree;
	eqnTree.createTree(equation);
//	cout << eqnTree.value();
	vector<VarNode*> indVar = inputConstantValues(equation);


    SDL_Init(SDL_INIT_EVERYTHING);
 
	SDL_Window * window = SDL_CreateWindow("Close me with the X", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// you probably want SDL_RENDERER_ACCELERATED in flags at least, I'm doing this on remote desktop!
	SDL_Renderer * renderer = window ? SDL_CreateRenderer(window, -1, 0) : NULL;

	if (!window || !renderer)
	{
		std::cerr << SDL_GetError() << "\n";

		SDL_Quit();

		return 0;
	}

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		while ( SDL_PollEvent(&event) )
		{
			if (event.type == SDL_QUIT)
				quit = true;
		}


		
//		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//		SDL_RenderDrawLine(renderer, x, y, x2, y2);
		renderExpressionTree(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, eqnTree, indVar, range);


		SDL_RenderPresent(renderer);
		SDL_Delay(1); 
		
	}
	
	SDL_DestroyRenderer(renderer);

    SDL_Quit();
 
    return 0;
}