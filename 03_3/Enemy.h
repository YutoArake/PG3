#pragma once

// 敵
class Enemy {
public:
	// 列挙
	enum class Phase {
		APPROACH,
		SHOOT,
		LEAVE
	};

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	// 接近
	void Approach();
	// 射撃
	void Shoot();
	// 離脱
	void Leave();
private:
	// メンバ関数ポインタ
	static void (Enemy::* spFuncTable[])();
	// フェーズ
	Phase phase_;
	// タイム
	int approachTime;
	int shootTime;
	int leaveTime;
	// 死亡フラグ
	bool isDead;
};