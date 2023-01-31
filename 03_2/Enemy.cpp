#include "Enemy.h"
#include <stdio.h>

// �ÓI�����o�ϐ��̎���
bool Enemy::isAllDead = false;

void Enemy::Initialize() {
	isDead = false;
}

void Enemy::Update() {
	if (isAllDead) {
		isDead = true;
	}

	if (!isDead) {
		printf("����!\n\n");
	}
	else {
		printf("���S!\n\n");
	}
}

void Enemy::ClearAllEnemy() {
	isAllDead = true;
}