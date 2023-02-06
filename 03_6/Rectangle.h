#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public: // メンバ関数
	// コンストラクタ
	Rectangle(float height, float width);
	// 面積計算
	void Size() override;
	// 計算結果
	void Draw() override;

private: // メンバ変数
	// 縦
	float height;
	// 横
	float width;
	// 面積
	float size;
};