#include "Enemy.h"
#include <stdio.h>

int main() {
	// �ϐ��錾
	Enemy* enemy = new Enemy();
	int inputNum;

	// ������
	enemy->Initialize();

	// ���[�v
	while (true) {
		printf("�R�}���h\n");
		printf("0 = ���̃t���[���֐i�ށA����ȊO�Ȃ�i�܂Ȃ�\n");
		scanf_s("%d", &inputNum);

		if (inputNum == 0) {
			enemy->Update();
		}
	}

	delete enemy;

	return 0;
}