#include <SDL.h>
#include <stdio.h>
#define ERR(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and create window
bool init();
//load media
bool loadMedia();
//Free media and shutdown SDL
void close();

//some global variable
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gBMPFile = NULL;

int main(int argc, char *args[])
{
	
	if (!init())
	{
		ERR("Failed to initialize!");
	}
	if (!loadMedia())
	{
		ERR("Failed to load media!");
	}
	else
	{
		//render to back buffer
		SDL_BlitSurface(gBMPFile, NULL, gScreenSurface, NULL);
		//update the back buffer to front
		SDL_UpdateWindowSurface(gWindow);
		SDL_Delay(2000);
	}
	printf("Close program\n");
	close();
	return 0;
}
bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ERR("SDL could not initialize SDL_Error:%s", SDL_GetError());
		return false; //init fail
	}else{
		gWindow = SDL_CreateWindow( "SDL load bmp file", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			ERR( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
		return true;
	}

	//Get the surface in the window
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	return true;
}

bool loadMedia()
{
	gBMPFile = SDL_LoadBMP("snoopy.bmp");
	if (gBMPFile == NULL)
	{
		ERR("Unable to load image %s SDL Error %s", "snoopy.bmp", SDL_GetError);
		return false;
	}
	return true;
}

void close()
{
	SDL_FreeSurface(gBMPFile); //allocate memory with SDL_LoadBMP
	gBMPFile = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}