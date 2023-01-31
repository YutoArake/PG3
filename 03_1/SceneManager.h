#pragma once

// シーンマネージャー
class SceneManager {
public:
	// 列挙
	enum Scene {
		NONE,
		TITLE,				// タイトル
		NEW_GAME,		// ニューゲーム
		GAME_PLAY,		// プレイ
		GAME_CLEAR,	// クリア

		SCENE_NUM		// シーン数
	};
	
private:
	SceneManager();
	~SceneManager();

public: // メンバ関数
	// コピーコンストラクタを無効にする
	SceneManager(const SceneManager& obj) = delete;
	// 代入演算子を無効にする
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	/// <summary>
	/// シーン切り替え
	/// </summary>
	/// <param name="sceneNo">シーン番号</param>
	void ChangeScene(int sceneNo);

private: // メンバ変数
	int sceneNum_ = NONE;
};