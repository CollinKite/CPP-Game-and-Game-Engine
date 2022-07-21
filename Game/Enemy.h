#pragma once
#include "Framework/Actor.h"

	class Enemy : public crae::Actor
	{
	public:
		Enemy() = default;
		Enemy(const crae::Model& model, const crae::Transform& transform) : Actor{ model, transform } {}

		void Update() override;

	private:
		float m_speed = 12;
	};