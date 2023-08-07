#include "Paddle.hpp"

Paddle::Paddle(Type type, int x, int y) {
	position.x = x;
	position.y = y;
	position.w = 25;
	position.h = 75;
	m_y = static_cast<double>(y);
	m_type = type;
	movementDirection = Direction::NONE;
	score = 0;
}

void Paddle::handleInput(SDL_Event const &event){
	switch (event.type) {
		case SDL_KEYDOWN:
			Uint8 const* keys = SDL_GetKeyboardState(nullptr);

			//Left paddle event handler
			if (m_type == Type::LEFT) {
				if (keys[SDL_SCANCODE_W]) {
					movementDirection = Direction::UP;

				}
				else if (keys[SDL_SCANCODE_S]) {
					movementDirection = Direction::DOWN;

				}
			}

			//Right paddle movement event handler
			if (m_type == Type::RIGHT) {
				if (keys[SDL_SCANCODE_UP]) {
					movementDirection = Direction::UP;

				}
				else if (keys[SDL_SCANCODE_DOWN]) {
					movementDirection = Direction::DOWN;

				}
			}
	}
}

//update the position of the paddle based on the direction it is moving by 5.0
void Paddle::update(double deltaTime){
	if (movementDirection == Direction::UP) {
		m_y = m_y - 12.0 * deltaTime;
		position.y = m_y;
	}
	else if (movementDirection == Direction::DOWN) {
		m_y = m_y + 12.0 * deltaTime;
		position.y = m_y;
	}
}

void Paddle::draw(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &position);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}