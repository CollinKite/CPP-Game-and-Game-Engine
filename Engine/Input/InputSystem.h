#pragma once
#include <vector>
#include <cstdint>

namespace crae
{
	class InputSystem
	{
	public:
		enum State
		{
			Idle,
			Pressed,
			Held,
			Released
		};

	public:
		InputSystem() = default; //Creates Default
		~InputSystem() = default; // Implicitly already made if you didn't add constructor, and destructor

		void Initialize();
		void Shutdown();

		void Update();

		bool GetKeyDown(int key) { return m_keyboardState[key]; }
		bool prevKeyDown(int key) { return m_prevKeyboardState[key]; }

	private:
		int m_numKeys;
		
		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;


	};

	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	extern const uint32_t key_escape; //Extern means it's avaliable - in C there's a symbol table that tells the code what variables are avaliable to use

}