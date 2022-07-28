#pragma once
#include "Framework/Actor.h"

class Player : public crae::Actor
{
public:
	Player() = default;
	Player(const crae::Model& model, const crae::Transform& transform, float health = 1) : Actor{ model, transform }, m_health {health} {}
	
	void Update() override;
	void OnCollision(Actor* other) override;

public:
	uint32_t key_up;
	uint32_t key_left;
	uint32_t key_right;
	uint32_t key_thrust;
	uint32_t key_shoot;

private:
	float m_health = {100};
	float m_speed{ 0 };
	float m_maxspeed{ 1000 };
	float m_thrustspeed{ 2500 };
};