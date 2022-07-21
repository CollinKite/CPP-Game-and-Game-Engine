#pragma once
#include "Framework/Actor.h"

	class Enemy : public crae::Actor
	{
	public:
		Enemy() = default;
		Enemy(const crae::Model& model, const crae::Transform& transform) : Actor{ model, transform } { Initialize(); }

		void Initialize();
		void Update() override;

	private:
		float m_speed = 12;
		float m_fireTimer = 0;
	};