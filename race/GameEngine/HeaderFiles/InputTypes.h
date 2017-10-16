#pragma once
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_gamecontroller.h>
#elif defined _WIN32 || defined _WIN64
#include <SDL.h>
#include <SDL_gamecontroller.h>
#endif

enum class INPUT_TYPES {
	A_BUTTON,
	B_BUTTON,
	X_BUTTON,
	Y_BUTTON,
	LEFT_ANALOG_Y,
	LEFT_ANALOG_X,
	RIGHT_ANALOG_X,
	RIGHT_ANALOG_Y,
	LEFT_D_PAD,
	RIGHT_D_PAD,
	UP_D_PAD,
	DOWN_D_PAD,
	START,
	BACK,
	RIGHT_TRIGGER,
	LEFT_TRIGGER,
	RIGHT_BUMBER,
	LEFT_BUMPER,
	LEFT_STICK_CLICK,
	RIGHT_STICK_CLICK
};