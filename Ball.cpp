#include "Ball.hpp"
#include <iostream>


Ball::~Ball() {
	SDL_DestroyTexture(m_image);
};

void Ball::init(SDL_Renderer* renderer, int x, int y) {
	IMG_Init(IMG_INIT_PNG);

	SDL_Surface* image = IMG_Load("ball.png");

	m_image = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	position.x = x;
	position.y = y;

	m_x = position.x;

	SDL_QueryTexture(m_image, nullptr, nullptr, &position.w, &position.h);

	std::random_device dev;
	std::mt19937 rand_gen(dev());
	std::uniform_int_distribution<> dist_x(0, 1);

	if (dist_x(rand_gen) == 0) {
		velocity_x = -3;
	}
	else {
		velocity_x = 3;
	}

	std::uniform_int_distribution<> dist_y(1, 3);
	velocity_y = dist_y(rand_gen);

	if (dist_x(rand_gen) == 0) {
		velocity_y = -velocity_y;
	}
};

void Ball::update(double deltaTime) {

	m_x = m_x + (velocity_x * deltaTime);
	m_y = m_y + (velocity_y * deltaTime);

	position.y = m_y;
	position.x = m_x;
};

void Ball::draw(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, m_image, nullptr, &position);
}