#pragma once

// 敵
class Enemy {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 全エネミーを消す
	/// </summary>
	/// <returns></returns>
	static void ClearAllEnemy();

private:
	// 全員を消すフラグ
	static bool isAllDead;

	// 死亡フラグ
	bool isDead;

};