#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"

void Enemy::Initialize()
{
	m_fireTimer = crae::randomf(2, 6);
}

void Enemy::Update()
{
	m_fireTimer -= crae::g_time.deltaTime;
	if (m_fireTimer <= 0)
	{
		m_fireTimer = crae::randomf(2, 6);
		crae::Transform transform = m_transform;
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(crae::Model{ "bullet.txt" }, transform);
		m_scene->Add(std::move(bullet));

	}

	//Set Rotation towards Player


	crae::Vector2 direction{ 1,0 };
	direction = crae::Vector2::Rotate(direction, m_transform.rotation);
	crae::Vector2 velocity = direction * m_speed * crae::g_time.deltaTime;

	m_transform.postition += velocity;

	if (m_transform.postition.x > crae::g_renderer.GetWidth()) m_transform.postition.x = 0;
	if (m_transform.postition.x < 0) m_transform.postition.x = crae::g_renderer.GetWidth();


	if (m_transform.postition.y > crae::g_renderer.GetHeight()) m_transform.postition.y = 0;
	if (m_transform.postition.y < 0) m_transform.postition.y = crae::g_renderer.GetHeight();
}
