#include "SceneManager.h"
#include <stdio.h>

int main() {
	// �C���X�^���X���擾����
	SceneManager* SceneM = SceneManager::GetInstance();

	// �ϐ��錾
	int SceneNum = 0;

	// ���[�v
	while (true) {
		printf("���̃V�[���֍s���ꍇ��0�������Ă�������\n");
		printf("1 = TITLE, 2 = NEWGAME, 3 = GAMEPLAY, 4 = GAMECLEAR\n");
		// ���͎�t
		scanf_s("%d", &SceneNum);
		// �V�[���؂�ւ�
		SceneM->ChangeScene(SceneNum);
	}

	return 0;
}