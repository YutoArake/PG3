#include "Enemy.h"
#include <stdio.h>

// 静的メンバ変数の実体
bool Enemy::isAllDead = false;

void Enemy::Initialize() {
	isDead = false;
}

void Enemy::Update() {
	if (isAllDead) {
		isDead = true;
	}

	if (!isDead) {
		printf("生存!\n\n");
	}
	else {
		printf("死亡!\n\n");
	}
}

void Enemy::ClearAllEnemy() {
	isAllDead = true;
}