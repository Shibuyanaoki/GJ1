#include "Enemy.h"

void Enemy::Initialize()
{
	//ランダム関数
	srand((unsigned int)time(NULL));
}

void Enemy::Update()
{
	while (enemyCount < 3) {
		if (enemyCount == 0) {
			count[0] = rand() % 3;
			enemyCount += 1;
		}

		if (enemyCount == 1) {
			temp = rand() % 3;
			if (temp != count[0]) {
				count[1] = temp;
				enemyCount += 1;
			}
		}

		if (enemyCount == 2) {
			temp = rand() % 3;
			if (temp != count[0] && temp != count[1]) {
				count[2] = temp;
				enemyCount += 1;
			}

		}
	}

	if (enemyCount == 3) {
		for (int i = 0; i < 3; i++) {

			enemy[i].x = location[count[i]].x;
			enemy[i].y = location[count[i]].y;

			locationCount[i] = count[i];
		}
	}
}

void Enemy::Draw()
{
	if (flag == 1) {
		timer++;
	}

	if (timer >= 30) {
		flag = 0;
		timer = 0;
	}

	if (flag == 0) {
		Novice::DrawSprite(0, 0, ika, 1.7f, 1.5f, 0.0, WHITE);
	}

	if (flag == 1) {
		Novice::DrawSprite(0, 0, ika2, 1.7f, 1.5f, 0.0, WHITE);
	}

	Novice::ScreenPrintf(0, 20 * 0, "enemy->HP%d", HP);

	Novice::DrawSprite((int)enemy[0].x, (int)enemy[0].y, scissors, 1.5, 1.5, 0.0, WHITE);
	Novice::DrawSprite((int)enemy[1].x, (int)enemy[1].y, paper, 1.5, 1.5, 0.0, WHITE);
	Novice::DrawSprite((int)enemy[2].x, (int)enemy[2].y, rock, 1.5, 1.5, 0.0, WHITE);

}

void Enemy::Damage()
{
	HP -= 1;
}

void Enemy::Reset() {
	enemyCount = 0;

}

void Enemy::Flag() {
	flag = 1;
}