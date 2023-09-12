#pragma once
#include "Novice.h"
#include "Bullet.h"
#include "Scene.h"

class Ship
{

public:
	void Inisialize();

	void Updata();

	void Draw();

	void Fire();

	void Damage();

private:

	int HP = 3;
	Bullet* bullet_ = nullptr;
	int timer = 0;
	int ship = Novice::LoadTexture("./Ship.png");
	int shipFire = Novice::LoadTexture("./ShipFire.png");

};

