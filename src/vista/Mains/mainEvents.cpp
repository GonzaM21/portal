#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "../Window.h"
#include "../Camara.h"
#include "../Gate/Gate.h"
#include "../Player/Player.h"
#include "../Constants.h"
#include "../Sprite.h"
#include "../EventsHandler.h"
#include "../Model.h"
int main(int argc, char **argv)
{
	try
	{
		Model model;
		EventsHandler eventsHandler(model);
		eventsHandler.handle();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
