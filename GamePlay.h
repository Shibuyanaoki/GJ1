#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Scene.h"
#include "Novice.h"
class GamePlay
{
public:
	void Initialize();

	void Update();

	void Draw();

private:

	Bullet* bullet_ = nullptr;
	Enemy* enemy_ = nullptr;
	Phase phase_ = Phase::CHOOSE;

	int animationTimer = 0;
	int timer = 60*5;

	int kumo = Novice::LoadTexture("./kumo.png");

	int sea[2] = {
		{ Novice::LoadTexture("./sea_1.png") },
		{ Novice::LoadTexture("./sea_2.png") }
	};


};

