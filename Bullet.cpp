#include "Bullet.h"

void Bullet::Inisialize() {
	input_ = Input::GetInstance();
}

void Bullet::Updata() {


	if (selectCount == 0 && selectFlag == 0) {


		if (input_->PushKey(DIK_1)&& selectFlag == 0) {
			bullet[0].x = location[0].x;
			locationCount[0] = 0;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_2)  && selectFlag == 0) {
			bullet[0].x = location[1].x;
			locationCount[0] = 1;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_3)  && selectFlag == 0) {
			bullet[0].x = location[2].x;
			locationCount[0] = 2;
			selectFlag = 1;
		}

	}

	if (selectCount == 1 && selectFlag == 0) {

		if (input_->PushKey(DIK_1) && locationCount[0] != 0) {
			bullet[1].x = location[0].x;
			locationCount[1] = 0;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_2) && locationCount[0] != 1) {
			bullet[1].x = location[1].x;
			locationCount[1] = 1;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_3)  && locationCount[0] != 2) {
			bullet[1].x = location[2].x;
			locationCount[1] = 2;
			selectFlag = 1;
		}

	}

	if (selectCount == 2 && selectFlag == 0) {

		if (input_->PushKey(DIK_1) && locationCount[0] != 0 && locationCount[1] != 0) {
			bullet[2].x = location[0].x;
			locationCount[2] = 0;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_2) && locationCount[0] != 1 && locationCount[1] != 1) {
			bullet[2].x = location[1].x;
			locationCount[2] = 1;
			selectFlag = 1;
		}

		if (input_->PushKey(DIK_3) && locationCount[0] != 2 && locationCount[1] != 2) {
			bullet[2].x = location[2].x;
			locationCount[2] = 2;
			selectFlag = 1;
		}

	}

	if (selectFlag == 1) {
		selectCount += 1;
		selectFlag = 0;
	}



	if (input_->PushKey(DIK_R)) {
		selectCount = 0;
		for (int i = 0; i < 3; i++) {
			locationCount[i] = 0;
			bullet[i].x = 0;

		}
	}

	IsSelectEnd();

}

void Bullet::Draw() {
	for (int i = 0; i < 3; i++) {
		Novice::DrawEllipse((int)bullet[0].x, (int)bullet[0].y, 32, 32, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawEllipse((int)bullet[1].x, (int)bullet[1].y, 32, 32, 0.0f, RED, kFillModeSolid);
		Novice::DrawEllipse((int)bullet[2].x, (int)bullet[2].y, 32, 32, 0.0f, GREEN, kFillModeSolid);
	}
}

bool Bullet::IsSelectEnd()
{
	if (selectCount == 3) {
		if (input_->PushKey(DIK_RETURN)) {
			return true;
		}

	}
	return false;
}

void Bullet::Reset()
{
	selectCount = 0;
	for (int i = 0; i < 3; i++) {
		locationCount[i] = 0;
		bullet[i].x = 0;
	}
}

