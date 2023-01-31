#include "SceneManager.h"
#include <stdio.h>

int main() {
	// インスタンスを取得する
	SceneManager* SceneM = SceneManager::GetInstance();

	// 変数宣言
	int SceneNum = 0;

	// ループ
	while (true) {
		printf("次のシーンへ行く場合は0を押してください\n");
		printf("1 = TITLE, 2 = NEWGAME, 3 = GAMEPLAY, 4 = GAMECLEAR\n");
		// 入力受付
		scanf_s("%d", &SceneNum);
		// シーン切り替え
		SceneM->ChangeScene(SceneNum);
	}

	return 0;
}