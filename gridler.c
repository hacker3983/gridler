#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#define color_toparam(color) color.r, color.g, color.b, color.a

int main(int argc, char** argv) {
	int width = 0, height = 0, row_count = 0, column_count = 0,
	    quit = 0;
	SDL_Rect grid_square = {0, 0, 40, 40};
	SDL_Color window_color = {0x12, 0x12, 0x12, 0xff}, grid_color = {0x00, 0xff, 0x00, 0xff};
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Event e;
	SDL_Window* window = SDL_CreateWindow("Grid Generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			900, 600, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	while(!quit) {
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				quit = 1; break;
			}
		}
		SDL_GetWindowSize(window, &width, &height);
		row_count = width / grid_square.w, column_count = height / (grid_square.h+2);
		SDL_SetRenderDrawColor(renderer, color_toparam(window_color));
		SDL_RenderClear(renderer);
		grid_square.x = abs((width - (grid_square.w) * row_count) / 2);
		grid_square.y = abs((height - (grid_square.h) * column_count) / 2);
		SDL_Rect new_gridsquare = {
			grid_square.x, grid_square.y,
			grid_square.w, grid_square.h
		};
		SDL_SetRenderDrawColor(renderer, color_toparam(grid_color));
		for(size_t i=0;i<row_count;i++) {
			for(size_t j=0;j<column_count;j++) {
				SDL_RenderDrawRect(renderer, &new_gridsquare);
				new_gridsquare.y += new_gridsquare.h;
			}
			new_gridsquare.x += new_gridsquare.w; new_gridsquare.y = grid_square.y;
		}
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
