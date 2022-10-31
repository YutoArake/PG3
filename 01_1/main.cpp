#include  <stdio.h>

// 関数テンプレート
template <typename T>
T Min(T a, T b) {
	return b < a ? b : a;
}

// オーバーライド(特殊化)
template<>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません\n");
	return 0;
}

// オーバーロード(多重定義)
const char* Min(char a, char b) {
	return "数字以外は代入できません\n";
}

int main() {
	printf("%d\n", Min<int>(114, 514));
	printf("%f\n", Min<float>(11.4f, 51.4f));
	printf("%f\n", Min<double>(5.14, 1.14));
	Min<char>('a', 'b');

	return 0;
}