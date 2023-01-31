#pragma once

class Sample {
private:
	int num;

public:
	// コンストラクタちゃん、今回はh内で定義
	Sample(int x = 0) { num = x; }

	// 代入演算子のオーバーロード、今回は、h内で定義(本来はcppで)
	Sample& operator=(const Sample& obj) {
		num = obj.num;
		return *this;
	}
};

