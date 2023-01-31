#pragma once

// �V�[���}�l�[�W���[
class SceneManager {
public:
	// ��
	enum Scene {
		NONE,
		TITLE,				// �^�C�g��
		NEW_GAME,		// �j���[�Q�[��
		GAME_PLAY,		// �v���C
		GAME_CLEAR,	// �N���A

		SCENE_NUM		// �V�[����
	};
	
private:
	SceneManager();
	~SceneManager();

public: // �����o�֐�
	// �R�s�[�R���X�g���N�^�𖳌��ɂ���
	SceneManager(const SceneManager& obj) = delete;
	// ������Z�q�𖳌��ɂ���
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	/// <summary>
	/// �V�[���؂�ւ�
	/// </summary>
	/// <param name="sceneNo">�V�[���ԍ�</param>
	void ChangeScene(int sceneNo);

private: // �����o�ϐ�
	int sceneNum_ = NONE;
};