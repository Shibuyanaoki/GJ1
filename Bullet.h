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
		{0,0},
		{0,0},
		{0,0},	
	};
	Vector2 location[3] = {
		{320,540},
		{640,540},
		{960,540},
	};

	
	//弾がどこに設置されたか確認する変数
	int locationCount[3] = {};
	//弾を設置したときに立つフラグ
	int selectFlag = 0;
	//弾を設置したか確認する変数
	int selectCount = 0;
	Input* input_ = nullptr;

	

};

