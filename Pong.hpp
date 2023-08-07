#include <SDL.h>
#include "Paddle.hpp"
#include "Ball.hpp"

class Pong {
public:
	Pong();
	~Pong() = default;

	void gameLoop();
	void update(double deltaTime);
	void draw();
	bool checkCollision(SDL_Rect a, SDL_Rect b);
	void checkAllCollisions();
	void checkScore();
	void resetGame();

private:
	SDL_Window*		m_game_window;
	SDL_Event		game_window_event;
	SDL_Renderer*	game_window_renderer;

	Paddle left_paddle;
	Paddle right_paddle;
	Ball ball;

};