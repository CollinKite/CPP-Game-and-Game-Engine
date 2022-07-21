#pragma once
#include "Framework/Actor.h"

class Player : public crae::Actor
{
public:
	Player() = default;
	Player(const crae::Model& model, const crae::Transform& transform) : Actor{ model, transform } {}
	
	void Update() override;

private:
	float m_speed{ 0 };
	float m_maxspeed{ 1000 };
};