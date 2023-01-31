#include "Enemy.h"
#include <stdio.h>

int main() {
	// 変数宣言
	Enemy* enemy = new Enemy();
	int inputNum;

	// 初期化
	enemy->Initialize();

	// ループ
	while (true) {
		printf("コマンド\n");
		printf("0 = 次のフレームへ進む、それ以外なら進まない\n");
		scanf_s("%d", &inputNum);

		if (inputNum == 0) {
			enemy->Update();
		}
	}

	delete enemy;

	return 0;
}