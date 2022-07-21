#include "Enemy.h"
#include "Engine.h"

void Enemy::Update()
{
	crae::Vector2 direction{ 1,0 };
	direction = crae::Vector2::Rotate(direction, m_transform.rotation);
	crae::Vector2 velocity = direction * m_speed * crae::g_time.deltaTime;

	m_transform.postition += velocity;

	if (m_transform.postition.x > crae::g_renderer.GetWidth()) m_transform.postition.x = 0;
	if (m_transform.postition.x < 0) m_transform.postition.x = crae::g_renderer.GetWidth();


	if (m_transform.postition.y > crae::g_renderer.GetHeight()) m_transform.postition.y = 0;
	if (m_transform.postition.y < 0) m_transform.postition.y = crae::g_renderer.GetHeight();
}
