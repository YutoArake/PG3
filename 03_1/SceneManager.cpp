#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

SceneManager* SceneManager::GetInstance() {
	// �֐���static�ϐ��Ƃ��Đ錾����
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
		printf("SceneNo. %d. �^�C�g��\n\n", sceneNum_);
	}
	else if (sceneNum_ == NEW_GAME) {
		printf("SceneNo. %d. �j���[�Q�[��\n\n", sceneNum_);
	}
	else if (sceneNum_ == GAME_PLAY) {
		printf("SceneNo. %d. �Q�[���v���C\n\n", sceneNum_);
	}
	else if (sceneNum_ == GAME_CLEAR) {
		printf("SceneNo. %d. �Q�[���N���A\n\n", sceneNum_);
	}
}