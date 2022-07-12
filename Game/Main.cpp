#include "Renderer/Renderer.h"
#include "Core\Memory.h" //header file to check for mem leak
#include "Math/Random.h"
#include "Input/InputSystem.h"
#include "Renderer/Model.h"
#include "Core/File.h"

#include <iostream>
#include<vector>

using namespace std;

int main()
{
	cout << crae::GetFilePath() << endl;
	crae::SetFilePath("../Assets");
	cout << crae::GetFilePath() << endl;
	size_t size;
	crae::GetFileSize("Model.txt", size);
	cout << size << endl;

	std::string buffer;
	crae::ReadFile("Model.txt", buffer);
	cout << buffer << endl;


	crae::Vector2 move{ 3, 0 };
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

	crae::Vector2 position{400, 300};

	//model.push_back(crae::Vector2(45, 56));
	//model.push_back(crae::Vector2(87, 200));
	//model.push_back(crae::Vector2(120, 150));
	//model.push_back(crae::Vector2(10, 30));

	crae::initializeMemory(); //Calls debug function for mem leak

	crae::Renderer renderer;
	crae::InputSystem inputSystem;

	renderer.Initialize();
	inputSystem.Initialize();

	renderer.CreateWindow("Neumont", 800, 600);
	renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	bool quit = false;
	while (!quit)
	{
		inputSystem.Update();

		if (inputSystem.GetKeyDown(crae::key_escape)) quit = true;

		if (inputSystem.GetKeyDown(crae::key_left))
		{
			//std::cout << "left\n";
			position.x -= 2;
		}

		if (inputSystem.GetKeyDown(crae::key_right))
		{
			//std::cout << "left\n";
			position.x += 2;
		}

		if (inputSystem.GetKeyDown(crae::key_up))
		{
			//std::cout << "left\n";
			position.y -= 2;
		}

		if (inputSystem.GetKeyDown(crae::key_down))
		{
			//std::cout << "left\n";
			position.y += 2;
		}
		angle += 0.2f;


		renderer.BeginFrame();
		model.Draw(renderer, position, angle, 5);

		renderer.EndFrame();
	}	
	renderer.Shutdown();
}