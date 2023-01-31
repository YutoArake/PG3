#pragma once

// �G
class Enemy {
public:
	// ��
	enum class Phase {
		APPROACH,
		SHOOT,
		LEAVE
	};

public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	// �ڋ�
	void Approach();
	// �ˌ�
	void Shoot();
	// ���E
	void Leave();
private:
	// �����o�֐��|�C���^
	static void (Enemy::* spFuncTable[])();
	// �t�F�[�Y
	Phase phase_;
	// �^�C��
	int approachTime;
	int shootTime;
	int leaveTime;
	// ���S�t���O
	bool isDead;
};