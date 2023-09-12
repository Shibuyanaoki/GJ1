#pragma once
#include "Vector2.h"
#include <Novice.h>
#include "Input.h"
class Bullet
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Damage();

	bool IsSelectEnd();

	void Reset();


	int GetLocationCount(int index) {
		return locationCount[index];
	}

private:

	Vector2 bullet[3] = {
		{1052,650},
		{1132,650},
		{1212,650},
	};
	Vector2 location[3] = {
		{300,540},
		{760,540},
		{1140,540},
	};


	//弾がどこに設置されたか確認する変数
	int locationCount[3] = {};
	//弾を設置したときに立つフラグ
	int selectFlag = 0;
	//弾を設置したか確認する変数
	int selectCount = 0;
	Input* input_ = nullptr;

	int rock = Novice::LoadTexture("./bulletGB.png");
	int paper = Novice::LoadTexture("./bulletPB.png");
	int scissors = Novice::LoadTexture("./bulletCB.png");

	int HP = 3;
	int timer = 0;
	int ship = Novice::LoadTexture("./Ship.png");
	int shipFire = Novice::LoadTexture("./ShipFire.png");
	int heart = Novice::LoadTexture("./player heart.png");
	int flag = 0;

};

