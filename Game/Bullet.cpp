#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"

	void Bullet::Update()
	{
		crae::Vector2 direction{ 1, 0 };

		direction = crae::Vector2::Rotate(direction, m_transform.rotation);
		crae::Vector2 velocity = direction * m_speed * crae::g_time.deltaTime; // move speed per second

		m_transform.postition += velocity;

		if (m_transform.postition.x > (float)crae::g_renderer.GetWidth()) m_destroy;
		if (m_transform.postition.x < 0) m_destroy;
		if (m_transform.postition.y > (float)crae::g_renderer.GetHeight()) m_destroy;
		if (m_transform.postition.y < 0) m_destroy;
	}

	void Bullet::OnCollision(Actor* other)
	{
		if (dynamic_cast<Player*>(other) && m_tag != "player" || dynamic_cast<Enemy*>(other) && m_tag != "enemy")
		{
			m_destroy = true;
		}
	}

