#include "Paddle.hpp"

Paddle::Paddle(int x, int y) {
	m_position.x = x;
	m_position.y = y;
	m_position.w = 50;
	m_position.h = 100;
}
Paddle::Paddle(int x, int y, int w, int h) {
	m_position.x = x;
	m_position.y = y;
	m_position.w = w;
	m_position.h = h;
}


void Paddle::handleInput(SDL_Event const& event){



}

void Paddle::update(double deltaTime){



}

void Paddle::draw(){



}
