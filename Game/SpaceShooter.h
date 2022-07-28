#pragma once
#include "Framework/Game.h"

namespace crae
{
	class Font;
	class Text;
	class Player;
}

class SpaceShooter : public crae::Game
{
public:
	SpaceShooter() = default;
	~SpaceShooter() = default;

	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(crae::Renderer& renderer) override;

	bool pause = false;

private:
	float m_spawnTimer = 0;
	std::unique_ptr<crae::Font> m_font;
	std::unique_ptr<crae::Text> m_titleText;
	std::unique_ptr<crae::Text> m_Text;
	std::unique_ptr<crae::Text> m_ScoreText;
	std::unique_ptr<crae::Text> m_PauseText;
};