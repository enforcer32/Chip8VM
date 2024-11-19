#pragma once

#include <cstdint>
#include <unordered_map>

/*
	Chip8 Keyboard Specifications
	16-Key Hexadecimal Keyboard: 0-F
	Represented in 16-byte Bool Array (true=Pressed, false=Not Pressed)
	Remap The Chip8 Keys into PC Keys
*/
#define C8VM_KEY_SIZE 16

namespace C8VM
{
	enum class KeyCode : uint8_t
	{
		N1, N2, N3, KC,
		N4,	N5,	N6, KD,
		N7,	N8,	N9, KE,
		KA, N0, KB, KF,
	};

	class Keyboard
	{
	public:
		Keyboard(const std::unordered_map<char, KeyCode>& remap = {});
		~Keyboard();

		bool IsKeyUp(char key) const;
		bool IsKeyDown(char key) const;
		void SetKey(char key, bool state);
		void Remap(const std::unordered_map<char, KeyCode>& remap);

	private:
		bool IsKeyUp(KeyCode key) const;
		bool IsKeyDown(KeyCode key) const;

	private:
		bool m_Remapped;
		bool m_KeyState[C8VM_KEY_SIZE];
		std::unordered_map<char, KeyCode> m_KeyMap;
	};
}
