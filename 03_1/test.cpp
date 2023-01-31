#include "test.h"

TestSingleton::TestSingleton() {}
TestSingleton::~TestSingleton() {}

TestSingleton* TestSingleton::GetInstance() {
	// 関数内static変数として宣言する
	static TestSingleton instance;

	return &instance;
}