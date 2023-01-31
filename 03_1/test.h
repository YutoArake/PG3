#pragma once
class TestSingleton final {
private:
	// コンストラクタをprivateにする
	TestSingleton();
	// デストラクタをprivateにする
	~TestSingleton();
public:
	// コピーコンストラクタを無効にする
	TestSingleton(const TestSingleton& obj) = delete;
	// 代入演算子を無効にする
	TestSingleton& operator=(const TestSingleton& obj) = delete;

	static TestSingleton* GetInstance();
};