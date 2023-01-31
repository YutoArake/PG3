#include "Enemy.h"
#include <stdio.h>

// Ã“Iƒƒ“ƒo•Ï”‚ÌÀ‘Ì
bool Enemy::isAllDead = false;

void Enemy::Initialize() {
	isDead = false;
}

void Enemy::Update() {
	if (isAllDead) {
		isDead = true;
	}

	if (!isDead) {
		printf("¶‘¶!\n\n");
	}
	else {
		printf("€–S!\n\n");
	}
}

void Enemy::ClearAllEnemy() {
	isAllDead = true;
}