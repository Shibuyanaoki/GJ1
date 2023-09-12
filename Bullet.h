#pragma once
#include "Vector2.h"
#include <Novice.h>
#include "Input.h"
class Bullet
{
public:
	void Inisialize();

	void Updata();

	void Draw();

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




};

