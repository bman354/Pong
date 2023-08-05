#include "Pong.hpp"




Pong::Pong() 
	:m_left_paddle(0, (400 / 2 - 50)),
	 m_right_paddle(400 - 50, ((400 / 2) - 50)) {

	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &m_game_window, &m_game_window_renderer);
}

void Pong::gameLoop() {
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&m_game_window_event) > 0) {
			switch (m_game_window_event.type) {
				case SDL_QUIT:
					running = false;
					break;






			}
		}
	}
	
}

void Pong::update(double deltaTime) {

}

void Pong::draw() {
	SDL_RenderClear(m_game_window_renderer);

	SDL_RenderPresent(m_game_window_renderer);
}