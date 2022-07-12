#include "Model.h"

namespace crae 
{
	void Model::Draw(Renderer& renderer, Vector2& position, float angle, float scale)
	{
		//crae::Color color;
		//color.r = crae::random(256);
		//color.g = crae::random(256);
		//color.b = crae::random(256);
		//color.a = 255;

		//draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			crae::Vector2 p1 = crae::Vector2::Rotate((m_points[i] * scale), angle) + position;
			crae::Vector2 p2 = crae::Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}
}

