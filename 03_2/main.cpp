#include "Enemy.h"
#include <stdio.h>

int main() {
	// 変数宣言
	Enemy* enemy1 = new Enemy();
	Enemy* enemy2 = new Enemy();
	Enemy* enemy3 = new Enemy();
	int inputNum;

	// 初期化
	enemy1->Initialize();
	enemy2->Initialize();
	enemy3->Initialize();

	// ループ
	while (true) {
		printf("コマンド\n");
		printf("0 = 敵を死亡させる、それ以外ならそのまま進む\n");
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