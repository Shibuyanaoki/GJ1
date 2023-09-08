#include "Enemy.h"

void Enemy::Inisialize()
{
	//ランダム関数
	srand((unsigned int)time(NULL));
}

void Enemy::Updata()
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

			locationCount[i] = count[i];
		}
	}
}

void Enemy::Draw()
{
	for (int i = 0; i < 3; i++) {
		Novice::DrawEllipse((int)enemy[0].x, (int)enemy[0].y, 32, 32, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawEllipse((int)enemy[1].x, (int)enemy[1].y, 32, 32, 0.0f, RED, kFillModeSolid);
		Novice::DrawEllipse((int)enemy[2].x, (int)enemy[2].y, 32, 32, 0.0f, GREEN, kFillModeSolid);
	}

	Novice::ScreenPrintf(0, 0 * 20, "HP%d", HP);

}

void Enemy::Damage()
{
	HP -= 1;
}

void Enemy::Reset() {
	enemyCount = 0;
	
}
