#include <SDL.h>
#include <stdio.h>
#define ERR(fmt, ...) fprintf(stderr, __VA_ARGS__"\n" )


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

int main( int argc, char* args[] ){
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0xFF, 0xFF ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

		 	//Wait two seconds
			SDL_Delay( 2000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();
	return 0;
}
bool init(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		ERR("SDL could not initialize SDL_Error:%s", SDL_GetError());
		return false; //init fail
	}
	//Get the surface in the window
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	return success;
}

bool loadMedia(){
	gBMPFile = SDL_LoadBMP();

}
