#include "Chip8VM/Util/Logger.h"
#include "Chip8VM/Chip8VM.h"

#include <SDL.h>
#include <iostream>

int main(int argc, char** argv)
{
	C8VM::Logger::Init();
	C8VM_LOG_INFO("Chip8VM");

	//
	C8VM::Chip8VM chip8VM;
	//

	std::unordered_map<char, C8VM::KeyCode> keymap;
	keymap[SDLK_1] = C8VM::KeyCode::N1;
	keymap[SDLK_2] = C8VM::KeyCode::N2;
	keymap[SDLK_3] = C8VM::KeyCode::N3;
	keymap[SDLK_c] = C8VM::KeyCode::KC;
	keymap[SDLK_4] = C8VM::KeyCode::N4;
	keymap[SDLK_5] = C8VM::KeyCode::N5;
	keymap[SDLK_6] = C8VM::KeyCode::N6;
	keymap[SDLK_d] = C8VM::KeyCode::KD;
	keymap[SDLK_7] = C8VM::KeyCode::N7;
	keymap[SDLK_8] = C8VM::KeyCode::N8;
	keymap[SDLK_9] = C8VM::KeyCode::N9;
	keymap[SDLK_e] = C8VM::KeyCode::KE;
	keymap[SDLK_a] = C8VM::KeyCode::KA;
	keymap[SDLK_0] = C8VM::KeyCode::N0;
	keymap[SDLK_b] = C8VM::KeyCode::KB;
	keymap[SDLK_f] = C8VM::KeyCode::KF;

	C8VM::Keyboard keyboard(keymap);

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window{ SDL_CreateWindow("Chip8VM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (C8VM_DISPLAY_WIDTH * C8VM_DISPLAY_SCALER), (C8VM_DISPLAY_HEIGHT * C8VM_DISPLAY_SCALER), SDL_WINDOW_SHOWN)};
	if (!window)
	{
		C8VM_LOG_ERROR("SDL_CreateWindow");
		return -1;
	}

	SDL_Renderer* renderer{ SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET) };
	if (!renderer)
	{
		C8VM_LOG_ERROR("SDL_CreateRenderer");
		return -1;
	}

	while (1)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				goto end;

			case SDL_KEYDOWN:
				keyboard.SetKey(ev.key.keysym.sym, true);
				C8VM_LOG_INFO("Key({}) Down?: {}", (char)ev.key.keysym.sym, keyboard.IsKeyDown(ev.key.keysym.sym));
				break;
			case SDL_KEYUP:
				keyboard.SetKey(ev.key.keysym.sym, false);
				C8VM_LOG_INFO("Key({}) Up?: {}", (char)ev.key.keysym.sym, keyboard.IsKeyUp(ev.key.keysym.sym));
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 125, 125, 125, 0);
		SDL_Rect rect = { .x = 0, .y = 0, .w = 40, .h = 40 };
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}

end:
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}
