#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Scene.h"
#include "Novice.h"
#include "Ship.h"
class GamePlay
{
public:
	void Inisialize();

	void Updata();

	void Draw();

private:

	Bullet* bullet_ = nullptr;
	Enemy* enemy_ = nullptr;
	Ship* ship_ = nullptr;
	Phase phase_ = Phase::CHOOSE;

	int animationTimer = 0;
	int timer = 60;
	int kumo = Novice::LoadTexture("./kumo.png");

	int sea[2] = {
		{ Novice::LoadTexture("./sea_1.png") },
		{ Novice::LoadTexture("./sea_2.png") }
	};


};

