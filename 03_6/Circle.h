#pragma once
#include "IShape.h"

class Circle : public IShape {
public: // メンバ関数
	// コンストラクタ
	Circle(float radius);
	// 面積計算
	void Size() override;
	// 計算結果
	void Draw() override;

private: // メンバ変数
	// 半径
	float radius;
	// 面積
	float size;
};