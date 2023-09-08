#include "GamePlay.h"

void GamePlay::Inisialize() {

	bullet_ = new Bullet;
	enemy_ = new Enemy;

	bullet_->Inisialize();
	enemy_->Inisialize();

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

		for (int i = 0; i < 3; i++) {
			if (bullet_->GetLocationCount(i) == enemy_->GetLocationCount(i)) {
				enemy_->Damage();
			}
		}

		bullet_->Reset();
		enemy_->Reset();

		phase_ = Phase::CHOOSE;

		break;


	}


}

void GamePlay::Draw() {
	bullet_->Draw();
	enemy_->Draw();

	Novice::DrawSprite(0, 0, sea[0], 1, 1, 0.0, WHITE);
	Novice::DrawSprite(0, 0, ship, 1, 1, 0.0, WHITE);

	
	//Novice::DrawSprite(0, 0, sea[1], 1, 1, 0.0, WHITE);

}
