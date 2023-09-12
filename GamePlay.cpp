#include "GamePlay.h"

void GamePlay::Inisialize() {

	bullet_ = new Bullet;
	enemy_ = new Enemy;
	ship_ = new Ship;

	bullet_->Inisialize();
	enemy_->Inisialize();
	ship_->Inisialize();
}

void GamePlay::Updata() {

	switch (phase_) {
	case Phase::CHOOSE:

		bullet_->Updata();
		enemy_->Updata();

		if (bullet_->IsSelectEnd() == true) {
			phase_ = Phase::FIRE;
		}

		break;

	case Phase::FIRE:


		if (bullet_->GetLocationCount(0) == enemy_->GetLocationCount(0) &&
			bullet_->GetLocationCount(1) == enemy_->GetLocationCount(1) &&
			bullet_->GetLocationCount(2) == enemy_->GetLocationCount(2))
		{
			enemy_->Damage();
		}


		for (int i = 0; i < 3; i++) {
			if (bullet_->GetLocationCount(i) != enemy_->GetLocationCount(i)) {
				ship_->Damage();
				break;
			}
		}

		bullet_->Reset();
		enemy_->Reset();

		phase_ = Phase::CHOOSE;

		break;
	}

}

void GamePlay::Draw() {

	animationTimer++;

	Novice::DrawSprite(0, 0, kumo, 1, 1, 0.0, WHITE);

	if (animationTimer <= 30) {
		Novice::DrawSprite(0, 0, sea[0], 1, 1, 0.0, WHITE);
	}

	if (animationTimer >= 30) {
		Novice::DrawSprite(0, 0, sea[1], 1, 1, 0.0, WHITE);
	}

	

	Novice::ScreenPrintf(0, 20 * 2, "timer%d", animationTimer);
	enemy_->Draw();
	ship_->Draw();
	bullet_->Draw();

	if (bullet_->IsSelectEnd() == true) {
		if (animationTimer <= 60) {
			ship_->Fire();
		}
	}

	if (animationTimer >= 60) {
		animationTimer = 0;
	}

}
