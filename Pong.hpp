#pragma once

#include <SDL.h>
#include "Paddle.hpp"

class Pong {
public:
	Pong();
	~Pong() = default;

	void gameLoop();
	void update(double deltaTime);
	void draw();

private:
	SDL_Window*		m_game_window;
	SDL_Event		m_game_window_event;
	SDL_Renderer*	m_game_window_renderer;

	Paddle m_left_paddle;
	Paddle m_right_paddle;
};