#include "InputSystem.h"
#include<SDL.h>
#include <iostream>

namespace crae
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;


	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys); //Get the num of keys - pass through address and return address

		m_keyboardState.resize(m_numKeys); //resize vector so we have enough memory
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin()); //copy beginning, we get the end by the offset
		m_prevKeyboardState = m_keyboardState;

	}


	void InputSystem::Shutdown()
	{
		//
	}


	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		//save prev keyboard state
		m_prevKeyboardState = m_keyboardState;

		//get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		//std::cout << (bool)m_keyboardState[SDL_SCANCODE_SPACE] << std::endl;

		//for (auto state : m_keyboardState) //go through states in vector
		//{
		//	std::cout << (bool)state;
		//}
		//std::cout << std::endl;
	}
}