#include "Chip8VM/Keyboard.h"
#include "Chip8VM/Util/Logger.h"
#include "Chip8VM/Util/Assertion.h"

#include <cstring>
#include <string>

namespace C8VM
{
	Keyboard::Keyboard(const std::unordered_map<char, KeyCode>& remap)
		: m_Remapped(!remap.empty())
	{
		C8VM_LOG_INFO("C8VM->Keyboard Initializing...");
		std::memset(m_KeyState, 0, sizeof(m_KeyState));

		if (!m_Remapped)
		{
			m_KeyMap['1'] = KeyCode::N1;
			m_KeyMap['2'] = KeyCode::N2;
			m_KeyMap['3'] = KeyCode::N3;
			m_KeyMap['c'] = KeyCode::KC;
			m_KeyMap['4'] = KeyCode::N4;
			m_KeyMap['5'] = KeyCode::N5;
			m_KeyMap['6'] = KeyCode::N6;
			m_KeyMap['d'] = KeyCode::KD;
			m_KeyMap['7'] = KeyCode::N7;
			m_KeyMap['8'] = KeyCode::N8;
			m_KeyMap['9'] = KeyCode::N9;
			m_KeyMap['e'] = KeyCode::KE;
			m_KeyMap['a'] = KeyCode::KA;
			m_KeyMap['0'] = KeyCode::N0;
			m_KeyMap['b'] = KeyCode::KB;
			m_KeyMap['f'] = KeyCode::KF;
		}
		else
		{
			m_KeyMap = remap;
		}
		C8VM_LOG_INFO("C8VM->Keyboard Initialized!");
	}

	Keyboard::~Keyboard()
	{
		C8VM_LOG_INFO("C8VM->Keyboard Destroying...");
		C8VM_LOG_INFO("C8VM->Keyboard Destroyed!");
	}

	bool Keyboard::IsKeyUp(char key) const
	{
		return IsKeyUp(m_KeyMap.at(std::tolower(key)));
	}

	bool Keyboard::IsKeyDown(char key) const
	{
		return IsKeyDown(m_KeyMap.at(std::tolower(key)));
	}

	void Keyboard::SetKey(char key, bool state)
	{
		C8VM_ASSERT((m_KeyMap.find(std::tolower(key)) != m_KeyMap.end()), "C8VM::Keyboard->SetKey key Not Mapped");
		C8VM_ASSERT((uint8_t)m_KeyMap.at(std::tolower(key)) < C8VM_KEY_SIZE, "C8VM::Keyboard->SetKey key Out of Bounds");
		C8VM_LOG_DEBUG("C8VM->Keyboard SetKey(key={}, state={})", key, state);
		m_KeyState[(uint8_t)m_KeyMap.at(std::tolower(key))] = state;
	}

	void Keyboard::Remap(const std::unordered_map<char, KeyCode>& remap)
	{
		C8VM_LOG_DEBUG("C8VM->Keyboard Remap");
		m_KeyMap = remap;
	}

	bool Keyboard::IsKeyUp(KeyCode key) const
	{
		C8VM_ASSERT((uint8_t)key < C8VM_KEY_SIZE, "C8VM::Keyboard->IsKeyUp key Out of Bounds");
		return !m_KeyState[(uint8_t)key];
	}
	
	bool Keyboard::IsKeyDown(KeyCode key) const
	{
		C8VM_ASSERT((uint8_t)key < C8VM_KEY_SIZE, "C8VM::Keyboard->IsKeyDown key Out of Bounds");
		return m_KeyState[(uint8_t)key];
	}
}
