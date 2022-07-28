#include "SpaceShooter.h"
#include "Player.h"
#include "Engine.h"
#include "Enemy.h"

void SpaceShooter::Initialize()
{
	m_scene = std::make_unique<crae::Scene>(this);

	//Create Assets
	crae::g_audioSystem.AddAudio("laser", "laser.wav");
	crae::g_audioSystem.AddAudio("music", "music.wav");
	m_font = std::make_unique<crae::Font>("fonts/arcade.ttf", 14);

	m_titleText = std::make_unique<crae::Text>(m_font.get());
	m_titleText->Create(crae::g_renderer, "Astroids", {0,0,255,255});

	m_ScoreText = std::make_unique<crae::Text>(m_font.get());
	m_ScoreText->Create(crae::g_renderer, "000000", { 0,0,255,255 });


	m_PauseText = std::make_unique<crae::Text>(m_font.get());
	m_PauseText->Create(crae::g_renderer, "Pause", { 0,0,255,255 });


	// ** MAKE ACTOR **
	//transform
	crae::Transform transform;
	transform.postition = crae::Vector2{ 400,300 };
	transform.rotation = 0;
	transform.scale = 5;

	std::unique_ptr<Player> player = std::make_unique<Player>(crae::Model{ "player1.txt" }, transform, 10000);
	player->key_up = crae::key_up;
	player->key_left = crae::key_left;
	player->key_right = crae::key_right;
	player->key_thrust = crae::key_RShift;
	player->key_shoot = crae::key_RCTRL;
	m_scene->Add(std::move(player));

	std::unique_ptr<Player> player2 = std::make_unique<Player>(crae::Model{ "player2.txt" }, transform, 10000);
	player2->key_up = crae::key_W;
	player2->key_left = crae::key_A;
	player2->key_right = crae::key_D;
	player2->key_thrust = crae::key_LShift;
	player2->key_shoot = crae::key_space;
	m_scene->Add(std::move(player2));



	//for (int i = 0; i < 1; i++)
	//{
	//	transform.postition.x = crae::randomf(800);
	//	transform.postition.y = crae::randomf(600);
	//	transform.rotation = crae::randomf(math::DoublePi);
	//	std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(crae::Model{ "Enemy.txt" }, transform);
	//	m_scene->Add(std::move(enemy));
	//}

	//Create Window
	
	//crae::Font* font = new crae::Font("fonts/Montserrat.ttf", 24);
	//crae::Text title(font);
	//title.Create(crae::g_renderer, "Paused", { 0, 0, 255, 255 });
}

void SpaceShooter::Shutdown()
{
}


void SpaceShooter::Update()
{
	//spawn enemys
	m_spawnTimer -= crae::g_time.deltaTime;
	if (m_spawnTimer <= 0)
	{
		m_spawnTimer = 2;

		crae::Transform transform;

		transform.postition.x = crae::randomf(800);
		transform.postition.y = crae::randomf(600);
		transform.rotation = crae::randomf(math::DoublePi);
		transform.scale = 6;
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(crae::Model{ "Enemy.txt" }, transform, 3.0f);
		m_scene->Add(std::move(enemy));
	}
	//update scene
	m_scene->Update();

	//update Score text
	m_ScoreText->Create(crae::g_renderer, std::to_string(m_score), { 0,0,255,255 });
}

void SpaceShooter::Draw(crae::Renderer& renderer)
{
	m_scene->Draw(renderer);
	m_titleText->Draw(renderer, { 670, 30 });
	m_ScoreText->Draw(renderer, { 40, 30 });
	if (pause)
	{
		m_PauseText->Draw(crae::g_renderer, { 400, 300 });
	}

}
