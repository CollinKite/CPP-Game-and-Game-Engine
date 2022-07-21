#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace crae
{
	class Scene; //fwd Delcaration

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : GameObject{ transform }, m_model{ model } {}

		virtual void Update() override {}; //Overide method from Game Object
		virtual void Draw(Renderer& renderer);

		friend class Scene;
	protected:
		bool m_destroy = false;
		//physics
		float m_damping = 1;
		Vector2 m_velocity;

		Scene* m_scene = nullptr;
		Model m_model;
	};
}