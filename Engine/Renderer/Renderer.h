#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
struct SDL_Renderer;
struct SDL_Window;

namespace crae
{
	class Renderer
	{
	public:
		bool isFullscreen = false;

		Renderer() = default; //Creates Default
		~Renderer() = default; // Implicitly already made if you didn't add constructor, and destructor

		void Initialize();
		void Shutdown();

		void CreateWindow(const char * name, int width, int height);
		void SetWindowFullScreen();
		void BeginFrame(); //Clear screen so we can draw to it
		void EndFrame();
		void SetClearColor(const Color& color) { m_clearColor = color; }

		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawLine(const Vector2& v1, const Vector2& v2, const Color& color);
		void DrawPoint(float x, float y);
		void DrawPoint(const Vector2& v, const Color& color);

		int GetWidth() { return m_width; }
		int GetHeight() { return m_height; }
		
		friend class Text;


	private:
		int m_width = 0;
		int m_height = 0;
		Color m_clearColor{ 0, 0, 0, 255 };

		SDL_Renderer* m_renderer = nullptr; //member variables
		SDL_Window* m_window = nullptr;
	};
}