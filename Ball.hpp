#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Paddle.hpp"


class Ball {
public:
	Ball() = default;
	~Ball();

	void init(SDL_Renderer* renderer, int x, int y);
	void update(double deltaTime);
	void draw(SDL_Renderer* renderer);
	
	SDL_Rect position;
	int velocity_x;
	int velocity_y;

private:
	double m_y;
	double m_x;
	SDL_Texture* m_image;
};





