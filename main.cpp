/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>


#include "Particle.cpp"

int main(int argc, char* argv[]) {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Simulation" ,
		SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH , SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if(!window) {
		std::cerr << "Window could not be created! SDL_Error: "<< SDL_GetError() << "\n";
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED);

	std::vector<Particle> particles;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(-50.0f , 50.0f);


	//spawn 100 particles at center
	for(int i=0; i < 100 ; i++) {
		particles.emplace_back(SCREEN_WIDTH / 2.0f ,SCREEN_HEIGHT / 2.0f , dist(gen) , dist(gen));
	}

	bool running = true;
	SDL_Event event;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	while(running) {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime  = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency()) / 1000.0;

		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT)
				running = false;
		}

		//update particles;
		for(auto &p : particles) {
			p.applyForce(0, 98.0f); //gravity (in px/s^2);
			p.update(static_cast<float>(deltaTime));
		}

		//Clear screen
		SDL_SetRenderDrawColor(renderer , 0 , 0 , 0 , 255); //black
		SDL_RenderClear(renderer);

		//Draw particles
		SDL_SetRenderDrawColor(renderer , 255,255,255,255); //white

		for(const auto& p : particles) {
			SDL_Rect rect = {(int)p.x , (int)p.y , 2, 2 };
			SDL_RenderFillRect(renderer , &rect);
		}

		SDL_RenderPresent(renderer);

		//cap frame rate (optional)
		SDL_Delay(16); // ~60 FPS
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}