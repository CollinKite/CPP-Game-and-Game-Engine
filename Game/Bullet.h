#pragma once
#include "Framework/Actor.h"
class Bullet : public crae::Actor
{
public:
	Bullet() = default;
	Bullet(const crae::Model& model, const crae::Transform& transform) : Actor{ model, transform } {}

	void Update() override;
private:
	float m_speed = 200;
};