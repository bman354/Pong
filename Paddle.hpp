#pragma once

#include <SDL.h>


class Paddle {
public:
	
	//constructor/destructor
	Paddle(int x, int y);
	~Paddle() = default;

	void handleInput(SDL_Event const& event);
	void update(double deltaTime);
	void draw();

private:
	SDL_Rect m_position;
};




