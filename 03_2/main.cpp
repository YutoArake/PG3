#include "Enemy.h"
#include <stdio.h>

int main() {
	// �ϐ��錾
	Enemy* enemy1 = new Enemy();
	Enemy* enemy2 = new Enemy();
	Enemy* enemy3 = new Enemy();
	int inputNum;

	// ������
	enemy1->Initialize();
	enemy2->Initialize();
	enemy3->Initialize();

	// ���[�v
	while (true) {
		printf("�R�}���h\n");
		printf("0 = �G�����S������A����ȊO�Ȃ炻�̂܂ܐi��\n");
		scanf_s("%d", &inputNum);

		if (inputNum == 0) {
			Enemy::ClearAllEnemy();
		}

		enemy1->Update();
		enemy2->Update();
		enemy3->Update();
	}

	return 0;
}