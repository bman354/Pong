#include "Pong.hpp"
#include <iostream>

Pong::Pong() : left_paddle(Paddle::Type::LEFT, 0, (400 / 2) - 50), right_paddle(Paddle::Type::RIGHT, 400 - 25, (400 / 2) - 50)
{
	SDL_CreateWindowAndRenderer(400, 400, SDL_WINDOW_RESIZABLE, &m_game_window, &game_window_renderer);

	SDL_RenderSetLogicalSize(game_window_renderer, 400, 400);

	ball.init(game_window_renderer, (400 / 2), (400 / 2));

}

void Pong::gameLoop() {
	
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&game_window_event) > 0) {
			
			//start of main event loop
			
			switch (game_window_event.type) {
				case SDL_QUIT:
					running = false;
					break;
			}

			left_paddle.handleInput(game_window_event);
			right_paddle.handleInput(game_window_event);
			//end of event loop
		}

		checkAllCollisions();
		checkScore();


		update(getDeltaTime());
		draw();


	}
	
}

void Pong::update(double deltaTime) {

	left_paddle.update(deltaTime);
	right_paddle.update(deltaTime);

	ball.update(deltaTime);

}

void Pong::draw() {
	//clear game window
	SDL_RenderClear(game_window_renderer);

	left_paddle.draw(game_window_renderer);
	right_paddle.draw(game_window_renderer);

	ball.draw(game_window_renderer);


	//display render
	SDL_RenderPresent(game_window_renderer);
}

bool Pong::checkCollision(SDL_Rect a, SDL_Rect b) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	leftB = b.x;

	rightA = a.x + a.w;
	rightB = b.x + b.w;

	topA = a.y;
	topB = b.y;

	bottomA = a.y + a.h;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

void Pong::checkAllCollisions(){
	//ball bounces off top or bottom of screen
	if (ball.position.y <= 0) {
		ball.velocity_y = 10;
	}
	else if (ball.position.y >= 370) {
		ball.velocity_y = -10;
	}


	//ball bounces off left paddle
	if (checkCollision(ball.position, left_paddle.position)) {
		ball.velocity_x = (ball.velocity_x * -1) + 1;
	}
	//ball bounces off right paddle
	else if (checkCollision(ball.position, right_paddle.position)) {
		ball.velocity_x = (ball.velocity_x * -1) - 1;
	}


	//if the left paddle hits the bottom
	if ((left_paddle.position.y + left_paddle.position.h) >= 400) {
		left_paddle.movementDirection = Paddle::Direction::NONE;
		left_paddle.position.y = (399 - left_paddle.position.h);
	} 
	//if the left paddle hits the top
	else if (left_paddle.position.y <= 0) {
		left_paddle.movementDirection = Paddle::Direction::NONE;
		left_paddle.position.y = 1;
	}


	//if the Right paddle hits the bottom
	if ((right_paddle.position.y + right_paddle.position.h) > 400) {
		right_paddle.movementDirection = Paddle::Direction::NONE;
		right_paddle.position.y = 399 - right_paddle.position.h;
	}
	//if the Right paddle hits the top
	else if (right_paddle.position.y <= 0) {
		right_paddle.movementDirection = Paddle::Direction::NONE;
		right_paddle.position.y = 1;
	}
}

void Pong::checkScore() {
	if (ball.position.x < 0) {
		right_paddle.score++;
		std::cout << "Right Paddle Score: " << right_paddle.score << std::endl;
		resetGame();
	}
	else if(ball.position.x > 400){
		left_paddle.score++;
		std::cout << "left Paddle Score: " << left_paddle.score << std::endl;
		resetGame();
	}
}

void Pong::resetGame(){
	ball.m_x = 200.0;
	ball.m_y = 200.0;

	ball.randomizeVelocity();
}

double Pong::getDeltaTime() {
	static Uint64 LAST = SDL_GetPerformanceCounter();
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 FREQUENCY = SDL_GetPerformanceFrequency();

	double deltaTime = static_cast<double>(NOW - LAST) / static_cast<double>(FREQUENCY) * 1000.0; // Convert to milliseconds
	LAST = NOW;

	if (deltaTime > 1.0 / 60.0) {
		return (1.0 / 60.0);
	}
	return deltaTime;
}
