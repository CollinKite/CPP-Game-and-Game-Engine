#include "Renderer/Model.h"

#include "Bullet.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Engine.h"
#include "SpaceShooter.h"

#include <iostream>
#include<vector>
using namespace std;


int main()
{
	crae::initializeMemory(); //Calls debug function for mem leak
	crae::SetFilePath("../Assets");



	//Create Systems
	crae::g_renderer.Initialize();
	crae::g_inputSystem.Initialize();
	crae::g_audioSystem.Initialize();
	

	crae::g_renderer.CreateWindow("Astroids", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });
	{
		SpaceShooter game;
		game.Initialize();

		float spawnTimer = 2;

		bool quit = false;
		while (!quit)
		{
			crae::g_inputSystem.Update();
			crae::g_time.Tick(); //Increment time, and frame time
			crae::g_audioSystem.Update();


			//std::cout << crae::g_time.deltaTime << std::endl;

			if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;

			game.Update();

			if (crae::g_inputSystem.GetKeyDown(crae::key_p)) game.pause = !game.pause;
			crae::g_renderer.BeginFrame();

			game.Draw(crae::g_renderer);

			crae::g_renderer.EndFrame();
			while (game.pause)
			{
				crae::g_inputSystem.Update();
				crae::g_time.Tick(); //Increment time, and frame time
				if (crae::g_inputSystem.GetKeyDown(crae::key_up))
				{
					game.pause = !game.pause;
				}
				if (crae::g_inputSystem.GetKeyDown(crae::key_down))
				{
					game.pause = !game.pause;
				}
				if (crae::g_inputSystem.GetKeyDown(crae::key_left))
				{
					game.pause = !game.pause;
				}
				if (crae::g_inputSystem.GetKeyDown(crae::key_right))
				{
					game.pause = !game.pause;
				}
			}
		}
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();
}