#include "Ship.h"

void Ship::Inisialize() {
	bullet_ = new Bullet;
}

void Ship::Updata() {

}

void Ship::Draw() {
	Novice::DrawSprite(0, 0, ship, 1, 1, 0.0, WHITE);

	Novice::ScreenPrintf(0, 20 * 1, "ship->HP%d", HP);

}

void Ship::Damage() {
	HP -= 1;
}

void Ship::Fire() {

	Novice::DrawSprite(0, 0, shipFire, 1, 1, 0.0f, WHITE);
}