#include "Enemy.h"
#include <stdio.h>

// staticで宣言したメンバ関数ポインタテーブルの実体
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,	// 要素番号0
	&Enemy::Shoot,			// 要素番号1
	&Enemy::Leave,			// 要素番号2
};

void Enemy::Approach() {
	printf("接近中\n\n");
}

void Enemy::Shoot() {
	printf("射撃中\n\n");
}

void Enemy::Leave() {
	printf("離脱中\n\n");
}

void Enemy::Initialize() {
	phase_ = Phase::APPROACH;
	approachTime = 2;
	shootTime = 3;
	leaveTime = 2;
	isDead = false;
}

void Enemy::Update() {
	if (isDead) {
		printf("死亡\n\n");
		return;
	}

	// メンバ関数ポインタに入っている関数を呼び出す
	(this->*spFuncTable[static_cast<size_t>(phase_)])();

	// 接近し終わったら射撃へ
	if (approachTime <= 0) {
		phase_ = Phase::SHOOT;
	}
	// 射撃から終わったら離脱へ
	if (shootTime <= 0) {
		phase_ = Phase::LEAVE;
	}
	// 離脱が終わったら死亡
	if (leaveTime <= 0) {
		isDead = true;
	}

	if (phase_ == Phase::APPROACH) {
		approachTime--;
	}
	else if (phase_ == Phase::SHOOT) {
		shootTime--;
	}
	else if (phase_ == Phase::LEAVE) {
		leaveTime--;
	}
}