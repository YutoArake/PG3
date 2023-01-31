#include "Enemy.h"
#include <stdio.h>

// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,	// �v�f�ԍ�0
	&Enemy::Shoot,			// �v�f�ԍ�1
	&Enemy::Leave,			// �v�f�ԍ�2
};

void Enemy::Approach() {
	printf("�ڋߒ�\n\n");
}

void Enemy::Shoot() {
	printf("�ˌ���\n\n");
}

void Enemy::Leave() {
	printf("���E��\n\n");
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
		printf("���S\n\n");
		return;
	}

	// �����o�֐��|�C���^�ɓ����Ă���֐����Ăяo��
	(this->*spFuncTable[static_cast<size_t>(phase_)])();

	// �ڋ߂��I�������ˌ���
	if (approachTime <= 0) {
		phase_ = Phase::SHOOT;
	}
	// �ˌ�����I������痣�E��
	if (shootTime <= 0) {
		phase_ = Phase::LEAVE;
	}
	// ���E���I������玀�S
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