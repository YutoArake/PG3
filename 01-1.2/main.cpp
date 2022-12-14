#include <stdio.h>
#include <typeinfo>
#include <iostream>
using namespace std;

// 関数テンプレート
template <typename T>
T Max(T a, T b) {
	return b > a ? b : a;
}


int main() {
	// int型の値を比較
	int x = 10;
	int y = 20;

	cout << "x : " << x << " と y : " << y << " を比較" << endl;
	auto a = Max<int>(x, y);
	cout << "大きい値は" << a << endl;
	cout << "aの型 : " << typeid(a).name() << endl;		// #include <typeinfo> が必要

	// float型の値を比較
	float z = 12.3f;
	float w = 45.6f;

	cout << "z : " << z << " と w : " << w << " を比較" << endl;
	auto b = Max<float>(z, w);
	cout << "大きい値は" << b << endl;
	cout << "bの型 : " << typeid(b).name() << endl;	// #include <typeinfo> が必要

	return 0;
}