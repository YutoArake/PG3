#include <stdio.h>
#include <iostream>

// ‰æ‘œ‚ð•`‰æ
void DrawImage() {
	std::cout << "‰æ‘œ‚ð•`‰æ" << std::endl;
}

// ‰æ‘œ‚ð•`‰æ (ƒI[ƒo[ƒ[ƒh ˆø”2ŒÂ)
void DrawImage(int x, int y) {
	std::cout << "‰æ‘œ‚ð•`‰æ x : " << x << ", y : " << y << std::endl;
}

// ‰æ‘œ‚ð•`‰æ (ƒI[ƒo[ƒ[ƒh ˆø”3ŒÂ)
void DrawImage(int x, int y, int z) {
	std::cout << "‰æ‘œ‚ð•`‰æ x : " << x << ", y : " << y << ", z : " << z << std::endl;
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