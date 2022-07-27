#pragma once
#include "Framework/Actor.h"

	class Enemy : public crae::Actor
	{
	public:
		Enemy() = default;
		Enemy(const crae::Model& model, const crae::Transform& transform, float health = 1) : Actor{ model, transform }, m_health{health} { Initialize(); }

		void Initialize();
		void Update() override;

		void OnCollision(Actor* other) override;

	private:
		float m_health = 1;
		float m_speed = 12;
		float m_fireTimer = 0;
	};