#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace crae
{
	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(Model model, Transform transform) : GameObject{ transform }, m_model{ model } {}

		virtual void Update() override {}; //Overide method from Game Object
		virtual void Draw(Renderer& renderer);

	protected:
		Model m_model;
	};
}