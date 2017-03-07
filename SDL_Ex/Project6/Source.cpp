#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING);
	Uint32 rmask, gmask, bmask, amask;
	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_Surface * image = SDL_LoadBMP("spaceship.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
		image);
	SDL_FreeSurface(image);
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_Rect rectangle;
	rectangle.x = 295;
	rectangle.y = 215;
	rectangle.w = 64;
	rectangle.h = 64;

	while (!quit)
	{
		SDL_PollEvent(&event);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderDrawRect(renderer, &rectangle);
		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderPresent(renderer);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true; 
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:  rectangle.x-=1; break;
				if (rectangle.x < 0)
				{
					rectangle.x = 0;
				}
			case SDLK_RIGHT: rectangle.x+=1; break;
				if (rectangle.x > 640)
				{
					rectangle.x = 640;
				}
			case SDLK_UP:    rectangle.y-=1; break;
				if (rectangle.y < 0)
				{
					rectangle.y = 0;
				}
			case SDLK_DOWN:  rectangle.y+=1; break;
				if (rectangle.y < 480)
				{
					rectangle.y = 480;
				}
			case SDLK_ESCAPE: quit = true; break;
			}
			break;
		}
		}

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &rectangle);

	SDL_RenderPresent(renderer);

	

	return(EXIT_SUCCESS);
}