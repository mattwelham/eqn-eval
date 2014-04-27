#include "Main.h"
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void graphMain()
{
	vector<string> vtrStrEquation = createVtrStrEquation((inputStrEQN()));

	Equation equation;
	equation = evalVtrStrEquation(vtrStrEquation);
	if(validateEquation(equation) == false)
	{
		cout << "Invalid Equation, returning to menu:";
		return;
	}
	int* range = inputRange();
//	deleteNodes(equation);
	ExpressionTree eqnTree;
	eqnTree.createTree(equation);
//	cout << eqnTree.value();
	vector<VarNode*> indVar = inputConstantValues(equation);


    SDL_Init(SDL_INIT_EVERYTHING);
 
	SDL_Window * window = SDL_CreateWindow("Graphed Equation", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer * renderer = window ? SDL_CreateRenderer(window, -1, 0) : NULL;

	if (!window || !renderer)
	{
		std::cerr << SDL_GetError() << "\n";

		SDL_Quit();
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

		renderExpressionTree(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, eqnTree, indVar, range);


		SDL_RenderPresent(renderer);
		SDL_Delay(1); 
		
	}
	
	SDL_DestroyRenderer(renderer);

    SDL_Quit();
}