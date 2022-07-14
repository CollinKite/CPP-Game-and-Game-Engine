#pragma once
#include "Renderer.h"
#include <vector>
#include <string>

namespace crae
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<crae::Vector2>& points, const crae::Color& color) : m_points{points}, m_color{color} //Set private vars with constructor
		{
		}

		void Draw(Renderer& renderer, Vector2& position, float angle, float scale);

		void Load(const std::string& filename);


	private:
		crae::Color m_color;
		std::vector<crae::Vector2> m_points;
	};
}