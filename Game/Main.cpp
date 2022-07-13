#include "Renderer/Renderer.h"
#include "Core\Memory.h" //header file to check for mem leak
#include "Math/Random.h"
#include "Input/InputSystem.h"
#include "Renderer/Model.h"
#include "Core/File.h"
#include "Math/MathUtils.h"

#include <iostream>
#include<vector>

using namespace std;

int main()
{
	crae::SetFilePath("../Assets");

	crae::Vector2 position{400, 300};
	float angle = 0;

	vector<crae::Vector2> points
	{
		{ -5.00f, 4.00f },
		{ 0.00f, -9.00f },
		{ 5.00f, 4.00f },
		{ 0.00f, 1.00f },
		{ -5.00f, 4.00f }
	};

	crae::Model model(points, crae::Color{ 255, 255, 255, 255 });

	crae::initializeMemory(); //Calls debug function for mem leak

	//Create Systems
	crae::Renderer renderer;
	crae::InputSystem inputSystem;

	renderer.Initialize();
	inputSystem.Initialize();

	//Create Window
	renderer.CreateWindow("Neumont", 800, 600);
	renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	bool quit = false;
	while (!quit)
	{
		inputSystem.Update();

		cout << "x: " << inputSystem.GetMousePosition().x << endl << "y: " << inputSystem.GetMousePosition().y << endl;

		if (inputSystem.GetButtonDown(crae::button_left))
		{
			cout << "Left Mouse Button Pressed";
		}

		if (inputSystem.GetButtonDown(crae::button_middle))
		{
			cout << "Middle Mouse Button Pressed";
		}

		if (inputSystem.GetButtonDown(crae::button_right))
		{
			cout << "Right Mouse Button Pressed";
		}

		float thrust = 0;
		if (inputSystem.GetKeyDown(crae::key_escape)) quit = true;

		if (inputSystem.GetKeyDown(crae::key_left))
		{
			//std::cout << "left\n";
			//position.x -= 2;
			angle -= 0.1f;
		}

		if (inputSystem.GetKeyDown(crae::key_right))
		{
			//std::cout << "left\n";
			//position.x += 2;
			angle += 0.1f;
		}

		if (inputSystem.GetKeyDown(crae::key_up))
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
		crae::Vector2 target = inputSystem.GetMousePosition();
		target = target - position;
		angle = target.GetAngle();

		crae::Vector2 direction{ 1, 0 };

		direction = crae::Vector2::Rotate(direction, angle);
		crae::Vector2 velocity = direction * thrust;

		position += velocity;


		renderer.BeginFrame();
		model.Draw(renderer, position, angle + math::HalfPi, 5);

		renderer.EndFrame();
	}	
	renderer.Shutdown();
}