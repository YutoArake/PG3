#include <stdio.h>
#include <iostream>

// �摜��`��
void DrawImage() {
	std::cout << "�摜��`��" << std::endl;
}

// �摜��`�� (�I�[�o�[���[�h ����2��)
void DrawImage(int x, int y) {
	std::cout << "�摜��`�� x : " << x << ", y : " << y << std::endl;
}

// �摜��`�� (�I�[�o�[���[�h ����3��)
void DrawImage(int x, int y, int z) {
	std::cout << "�摜��`�� x : " << x << ", y : " << y << ", z : " << z << std::endl;
}

int main() {
	int x, y, z;
	x = 114;
	y = 514;
	z = 810;

	DrawImage();
	DrawImage(x, y);
	DrawImage(x, y, z);

	return 0;
}