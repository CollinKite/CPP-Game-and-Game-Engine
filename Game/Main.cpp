#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include <iostream>
#include<vector>
using namespace std;


int main()
{
	//time
	//uint32_t time = GetTickCount();//Dword or uint32_t (4 bytes, 32 bits)
	//cout << time << endl;




	crae::SetFilePath("../Assets");
	crae::Scene scene;

	// ** MAKE ACTOR **
	//transform
	crae::Transform transform;
	transform.postition = crae::Vector2{ 400,300 };
	transform.rotation = 0;
	transform.scale = 5;

	std::unique_ptr<Player> player = std::make_unique<Player>(crae::Model{ "model.txt" }, transform);
	scene.Add(std::move(player));

	for (int i = 0; i < 1; i++)
	{
		transform.postition.x = crae::randomf(800);
		transform.postition.y = crae::randomf(600);
		transform.rotation = crae::randomf(math::DoublePi);
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(crae::Model{ "Enemy.txt" }, transform);
		scene.Add(std::move(enemy));
	}

	//crae::Model model(points, crae::Color{ 255, 255, 255, 255 });
	/*crae::Model model;
	model.Load("model.txt");*/
	//Player player{ crae::Model{"player.txt"}, transform }; doesn't work need to fix

	

	//Player player{ model, transform };

	crae::initializeMemory(); //Calls debug function for mem leak

	//Create Systems
	
	

	crae::g_renderer.Initialize();
	crae::g_inputSystem.Initialize();
	crae::g_audioSystem.Initialize();
	crae::g_audioSystem.AddAudio("laser", "laser.wav");

	//Create Window
	crae::g_renderer.CreateWindow("Neumont", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });
	crae::Font* font = new crae::Font("fonts/Montserrat.ttf", 24);
	crae::Text title(font);
	title.Create(crae::g_renderer, "Paused", { 0, 0, 255, 255 });

	float spawnTimer = 2;

	bool quit = false;
	while (!quit)
	{
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time
		

		//std::cout << crae::g_time.deltaTime << std::endl;

		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;

		//spawn enemys
		spawnTimer -= crae::g_time.deltaTime;
		if (spawnTimer <= 0)
		{
			spawnTimer = 2;
			transform.postition.x = crae::randomf(800);
			transform.postition.y = crae::randomf(600);
			transform.rotation = crae::randomf(math::DoublePi);
			std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(crae::Model{ "Enemy.txt" }, transform);
			scene.Add(std::move(enemy));
		}

		scene.Update();

		bool pause = false;
		if (crae::g_inputSystem.GetKeyDown(crae::key_p)) pause = !pause;
		crae::g_renderer.BeginFrame();
		scene.Draw(crae::g_renderer);
		if (pause)
		{
			
			title.Draw(crae::g_renderer, { 400, 300 });
		}

		crae::g_renderer.EndFrame();
		while (pause)
		{
			if (crae::g_inputSystem.GetButtonDown(crae::button_))
			{
				pause = !pause;
			}
		}
	}
	delete font;
	crae::g_renderer.Shutdown();
}