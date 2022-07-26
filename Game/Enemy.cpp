#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"
#include "Player.h"

void Enemy::Initialize()
{
	m_fireTimer = crae::randomf(2, 6);
	m_speed = crae::randomf(20, 150);
}

void Enemy::Update()
{
	m_fireTimer -= crae::g_time.deltaTime;
	if (m_fireTimer <= 0)
	{
		m_fireTimer = crae::randomf(2, 6);
		crae::Transform transform = m_transform;
		transform.scale = 2;
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(crae::Model{ "bullet.txt" }, transform);
		m_scene->Add(std::move(bullet));
		crae::g_audioSystem.PlayAudio("laser");
	}

	//Set Rotation towards Player
	Player* player = m_scene->GetActor<Player>();
	if (player)
	{
		crae::Vector2 direction = player->GetTransform().postition - m_transform.postition;
		m_transform.rotation = direction.GetAngle();
	}

	crae::Vector2 direction{ 1,0 };
	direction = crae::Vector2::Rotate(direction, m_transform.rotation);
	crae::Vector2 velocity = direction * m_speed * crae::g_time.deltaTime;

	m_transform.postition += velocity;

	if (m_transform.postition.x > crae::g_renderer.GetWidth()) m_transform.postition.x = 0;
	if (m_transform.postition.x < 0) m_transform.postition.x = crae::g_renderer.GetWidth();


	if (m_transform.postition.y > crae::g_renderer.GetHeight()) m_transform.postition.y = 0;
	if (m_transform.postition.y < 0) m_transform.postition.y = crae::g_renderer.GetHeight();
}
