#include "Player.h"
#include "Engine.h"
#include "Math/MathUtils.h"
#include "Bullet.h"

#include <iostream>

void Player::Update()
{

	//std::cout << "x: " << crae::g_inputSystem.GetMousePosition().x << " " << "y: " << crae::g_inputSystem.GetMousePosition().y << std::endl;

	if (crae::g_inputSystem.GetButtonDown(crae::button_left))
	{
		//std::cout << "Left Mouse Button Pressed";
	}

	if (crae::g_inputSystem.GetButtonDown(crae::button_middle))
	{
		//std::cout << "Middle Mouse Button Pressed" << std::endl;
	}

	if (crae::g_inputSystem.GetButtonDown(crae::button_right))
	{
		//std::cout << "Right Mouse Button Pressed" << std::endl;
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

	if (crae::g_inputSystem.GetKeyDown(crae::key_LShift))
	{
		thrust = m_thrustspeed;
	}

	//if (inputSystem.GetKeyDown(crae::key_down))
	//{
	//	//std::cout << "left\n";
	//	position.y += 2;
	//}

	//face target
	/*crae::Vector2 target = crae::g_inputSystem.GetMousePosition();
	target = target - m_transform.postition;
	m_transform.rotation = target.GetAngle();*/


	//Calculate force
	crae::Vector2 direction{ 1, 0 };

	direction = crae::Vector2::Rotate(direction, m_transform.rotation);
	crae::Vector2 force = direction * thrust * crae::g_time.deltaTime; // move speed per second
	//Apply force to velocity
	m_velocity += force;
	//Apply drag
	m_damping = 3;
	m_velocity *= 1.0f / (1.0f + m_damping * crae::g_time.deltaTime);

	m_transform.postition += m_velocity * crae::g_time.deltaTime;

	if (m_transform.postition.x > (float)crae::g_renderer.GetWidth()) m_transform.postition.x = 0;
	if (m_transform.postition.x < 0) m_transform.postition.x = (float)crae::g_renderer.GetWidth();
	if (m_transform.postition.y > (float)crae::g_renderer.GetHeight()) m_transform.postition.y = 0;
	if (m_transform.postition.y < 0) m_transform.postition.y = (float)crae::g_renderer.GetHeight();

	//Fire bullet
	if (crae::g_inputSystem.GetKeyState(crae::key_space) == crae::InputSystem::Pressed)
	{
		//fire
		crae::Transform transform = m_transform;
		transform.scale = 2;
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(crae::Model{ "bullet.txt" }, transform, 100);
		bullet->GetTag() = "player";
		m_scene->Add(std::move(bullet));
		crae::g_audioSystem.PlayAudio("laser");
	}

}

void Player::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) && other->GetTag() == "enemy")
	{
		m_health -= dynamic_cast<Bullet*>(other)->GetDamage();
		if(m_health <= 0) m_destroy = true;
	}
}
