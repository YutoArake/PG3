#pragma once

class Human {
public:
	// コンストラクタ
	Human(const char* name);
	// デストラクタ
	~Human();
	// コピーコンストラクタ
	Human(const Human& obj);

private:
	const char* name;
};