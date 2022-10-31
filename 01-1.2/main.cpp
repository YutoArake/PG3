#include <stdio.h>
#include <typeinfo>
#include <iostream>
using namespace std;

// �֐��e���v���[�g
template <typename T>
T Max(T a, T b) {
	return b > a ? b : a;
}


int main() {
	// int�^�̒l���r
	int x = 10;
	int y = 20;

	cout << "x : " << x << " �� y : " << y << " ���r" << endl;
	auto a = Max<int>(x, y);
	cout << "�傫���l��" << a << endl;
	cout << "a�̌^ : " << typeid(a).name() << endl;		// #include <typeinfo> ���K�v

	// float�^�̒l���r
	float z = 12.3f;
	float w = 45.6f;

	cout << "z : " << z << " �� w : " << w << " ���r" << endl;
	auto b = Max<float>(z, w);
	cout << "�傫���l��" << b << endl;
	cout << "b�̌^ : " << typeid(b).name() << endl;	// #include <typeinfo> ���K�v

	return 0;
}