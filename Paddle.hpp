#pragma once

#include <SDL.h>


class Paddle {
public:
	enum class Type { LEFT, RIGHT };
	enum class Direction { NONE, UP, DOWN };
	//constructor/destructor
	Paddle(Type type, int x, int y);
	~Paddle() = default;

	void handleInput(SDL_Event const& event);
	void update(double deltaTime);
	void draw(SDL_Renderer* renderer);
	SDL_Rect position;
	Direction movementDirection;
	int score;


private:
	Type m_type;
	double m_y;
};



