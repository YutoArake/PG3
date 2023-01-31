#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

SceneManager* SceneManager::GetInstance() {
	// 関数内static変数として宣言する
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo) {
	if (sceneNo == NONE) {
		sceneNum_++;
		if (sceneNum_ > GAME_CLEAR) {
			sceneNum_ = TITLE;
		}
	}
	else {
		sceneNum_ = sceneNo;
	}

	if (sceneNum_ == TITLE) {
		printf("SceneNo. %d. タイトル\n\n", sceneNum_);
	}
	else if (sceneNum_ == NEW_GAME) {
		printf("SceneNo. %d. ニューゲーム\n\n", sceneNum_);
	}
	else if (sceneNum_ == GAME_PLAY) {
		printf("SceneNo. %d. ゲームプレイ\n\n", sceneNum_);
	}
	else if (sceneNum_ == GAME_CLEAR) {
		printf("SceneNo. %d. ゲームクリア\n\n", sceneNum_);
	}
}