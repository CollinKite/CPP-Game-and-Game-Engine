#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"

#include <iostream>
#include<vector>

using namespace std;


int main()
{
	crae::SetFilePath("../Assets");

	// ** MAKE ACTOR **
	//transform
	crae::Transform transform;
	transform.postition = crae::Vector2{ 400,300 };
	transform.rotation = 0;
	transform.scale = 5;

	vector<crae::Vector2> points
	{
		{ 3.00f, 0.00 },
		{ -2.00f, -3.00 },
		{ -1.00f, 0.00 },
		{ -2.00f, 3.00 },
		{ 3.00f, 0.00 }
	};

	crae::Model model(points, crae::Color{ 255, 255, 255, 255 });

	Player player{ model, transform };

	crae::initializeMemory(); //Calls debug function for mem leak

	//Create Systems
	crae::Renderer g_renderer;
	

	g_renderer.Initialize();
	crae::g_inputSystem.Initialize();

	//Create Window
	g_renderer.CreateWindow("Neumont", 800, 600);
	g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	bool quit = false;
	while (!quit)
	{
		crae::g_inputSystem.Update();

		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;

		player.Update();


		g_renderer.BeginFrame();
		player.Draw(g_renderer);

		g_renderer.EndFrame();
	}	
	g_renderer.Shutdown();
}