#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"

	void Bullet::Update()
	{
		//
		m_lifespan -= crae::g_time.deltaTime;
		if (m_lifespan <= 0)
		{
			m_destroy = true;
		}

		crae::Vector2 direction{ 1, 0 };

		direction = crae::Vector2::Rotate(direction, m_transform.rotation);
		crae::Vector2 velocity = direction * m_speed * crae::g_time.deltaTime; // move speed per second

		m_transform.postition += velocity;

		if (m_transform.postition.x > (float)crae::g_renderer.GetWidth()) m_transform.postition.x = 0;
		if (m_transform.postition.x < 0) m_transform.postition.x = (float)crae::g_renderer.GetWidth();
		if (m_transform.postition.y > (float)crae::g_renderer.GetHeight()) m_transform.postition.y = 0;
		if (m_transform.postition.y < 0) m_transform.postition.y = (float)crae::g_renderer.GetHeight();
	}

	void Bullet::OnCollision(Actor* other)
	{
		if (dynamic_cast<Player*>(other) && m_tag != "player")
		{
			m_destroy = true;
		}
		if (dynamic_cast<Enemy*>(other) && m_tag != "enemy")
		{
			m_destroy = true;
		}
	}

