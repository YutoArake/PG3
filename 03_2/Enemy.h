#pragma once

// �G
class Enemy {
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �S�G�l�~�[������
	/// </summary>
	/// <returns></returns>
	static void ClearAllEnemy();

private:
	// �S���������t���O
	static bool isAllDead;

	// ���S�t���O
	bool isDead;

};