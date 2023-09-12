#include "GamePlay.h"

void GamePlay::Initialize() {

	bullet_ = new Bullet;
	enemy_ = new Enemy;
	//ship_ = new Ship;

	bullet_->Initialize();
	enemy_->Initialize();
	//ship_->Initialize();
}

void GamePlay::Update() {

	switch (phase_) {
	case Phase::CHOOSE:

		timer--;

		enemy_->Update();

		if (timer >= 0) {
			bullet_->Update();
		}

		if (bullet_->IsSelectEnd() == true) {
			phase_ = Phase::FIRE;
		}

		if (timer <= 0) {
			phase_ = Phase::FIRE;
			timer = 60 * 5;
		}

		break;

	case Phase::FIRE:


		if (bullet_->GetLocationCount(0) == enemy_->GetLocationCount(0) &&
			bullet_->GetLocationCount(1) == enemy_->GetLocationCount(1) &&
			bullet_->GetLocationCount(2) == enemy_->GetLocationCount(2))
		{
			enemy_->Damage();
			enemy_->Flag();
		}


		for (int i = 0; i < 3; i++) {
			if (bullet_->GetLocationCount(i) != enemy_->GetLocationCount(i)) {
				bullet_->Damage();
				break;
			}
		}


		bullet_->Reset();
		enemy_->Reset();
		timer = 60 * 5;

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

	Novice::ScreenPrintf(0, 20 * 2, "timer%d", timer);
	enemy_->Draw();
	bullet_->Draw();

}
