#include  <stdio.h>

// �֐��e���v���[�g
template <typename T>
T Min(T a, T b) {
	return b < a ? b : a;
}

// �I�[�o�[���C�h(���ꉻ)
template<>
char Min<char>(char a, char b) {
	printf("�����ȊO�͑���ł��܂���\n");
	return 0;
}

// �I�[�o�[���[�h(���d��`)
const char* Min(char a, char b) {
	return "�����ȊO�͑���ł��܂���\n";
}

int main() {
	printf("%d\n", Min<int>(114, 514));
	printf("%f\n", Min<float>(11.4f, 51.4f));
	printf("%f\n", Min<double>(5.14, 1.14));
	Min<char>('a', 'b');

	return 0;
}