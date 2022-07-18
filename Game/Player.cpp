#include "Player.h"
#include "Engine.h"
#include "Math/MathUtils.h"

#include <iostream>

void Player::Update()
{

	//std::cout << "x: " << crae::g_inputSystem.GetMousePosition().x << " " << "y: " << crae::g_inputSystem.GetMousePosition().y << std::endl;

	if (crae::g_inputSystem.GetButtonDown(crae::button_left))
	{
		std::cout << "Left Mouse Button Pressed";
	}

	if (crae::g_inputSystem.GetButtonDown(crae::button_middle))
	{
		std::cout << "Middle Mouse Button Pressed" << std::endl;
	}

	if (crae::g_inputSystem.GetButtonDown(crae::button_right))
	{
		std::cout << "Right Mouse Button Pressed" << std::endl;
	}

	float thrust = m_speed;


	if (crae::g_inputSystem.GetKeyDown(crae::key_left))
	{
		m_transform.rotation -= math:: Pi * crae::g_time.deltaTime;
	}

	if (crae::g_inputSystem.GetKeyDown(crae::key_right))
	{
		//std::cout << "left\n";
		//position.x += 2;
		m_transform.rotation += 0.1f;
	}

	if (crae::g_inputSystem.GetKeyDown(crae::key_up))
	{
		thrust = m_maxspeed;
		//std::cout << "left\n";
		//position.y -= 2;
	}

	//if (inputSystem.GetKeyDown(crae::key_down))
	//{
	//	//std::cout << "left\n";
	//	position.y += 2;
	//}

	//face target
	crae::Vector2 target = crae::g_inputSystem.GetMousePosition();
	target = target - m_transform.postition;
	m_transform.rotation = target.GetAngle();

	crae::Vector2 direction{ 1, 0 };

	direction = crae::Vector2::Rotate(direction, m_transform.rotation);
	crae::Vector2 velocity = direction * thrust * crae::g_time.deltaTime; // move speed per second

	m_transform.postition += velocity;

}