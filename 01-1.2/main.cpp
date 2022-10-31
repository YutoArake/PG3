#include <stdio.h>
#include <typeinfo>
#include <iostream>
using namespace std;

// ŠÖ”ƒeƒ“ƒvƒŒ[ƒg
template <typename T>
T Max(T a, T b) {
	return b > a ? b : a;
}


int main() {
	// intŒ^‚Ì’l‚ğ”äŠr
	int x = 10;
	int y = 20;

	cout << "x : " << x << " ‚Æ y : " << y << " ‚ğ”äŠr" << endl;
	auto a = Max<int>(x, y);
	cout << "‘å‚«‚¢’l‚Í" << a << endl;
	cout << "a‚ÌŒ^ : " << typeid(a).name() << endl;		// #include <typeinfo> ‚ª•K—v

	// floatŒ^‚Ì’l‚ğ”äŠr
	float z = 12.3f;
	float w = 45.6f;

	cout << "z : " << z << " ‚Æ w : " << w << " ‚ğ”äŠr" << endl;
	auto b = Max<float>(z, w);
	cout << "‘å‚«‚¢’l‚Í" << b << endl;
	cout << "b‚ÌŒ^ : " << typeid(b).name() << endl;	// #include <typeinfo> ‚ª•K—v

	return 0;
}