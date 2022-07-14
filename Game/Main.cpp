#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Player.h"

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
	crae::Renderer renderer;
	

	renderer.Initialize();
	crae::g_inputSystem.Initialize();

	//Create Window
	renderer.CreateWindow("Neumont", 800, 600);
	renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	bool quit = false;
	while (!quit)
	{
		crae::g_inputSystem.Update();

		cout << "x: " << crae::g_inputSystem.GetMousePosition().x << " " << "y: " << crae::g_inputSystem.GetMousePosition().y << endl;

		if (crae::g_inputSystem.GetButtonDown(crae::button_left))
		{
			cout << "Left Mouse Button Pressed";
		}

		if (crae::g_inputSystem.GetButtonDown(crae::button_middle))
		{
			cout << "Middle Mouse Button Pressed" << endl;
		}

		if (crae::g_inputSystem.GetButtonDown(crae::button_right))
		{
			cout << "Right Mouse Button Pressed" << endl;
		}

		float thrust = 0;
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;

		if (crae::g_inputSystem.GetKeyDown(crae::key_left))
		{
			player.GetTransform().rotation -= 0.1f;
		}

		if (crae::g_inputSystem.GetKeyDown(crae::key_right))
		{
			//std::cout << "left\n";
			//position.x += 2;
			player.GetTransform().rotation += 0.1f;
		}

		if (crae::g_inputSystem.GetKeyDown(crae::key_up))
		{
			thrust = 10;
			//std::cout << "left\n";
			//position.y -= 2;
		}

		//if (inputSystem.GetKeyDown(crae::key_down))
		//{
		//	//std::cout << "left\n";
		//	position.y += 2;
		//}

		//face target
		crae::Vector2 target = crae::g_inputSystem.GetMousePosition();
		target = target - player.GetTransform().postition;
		player.GetTransform().rotation = target.GetAngle();

		crae::Vector2 direction{ 1, 0 };

		direction = crae::Vector2::Rotate(direction, player.GetTransform().rotation);
		crae::Vector2 velocity = direction * thrust;

		player.GetTransform().postition += velocity;


		renderer.BeginFrame();
		player.Draw(renderer);

		renderer.EndFrame();
	}	
	renderer.Shutdown();
}