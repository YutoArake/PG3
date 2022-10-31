#include <stdio.h>
#include <Windows.h>
#include <random>

//乱数シード生成器
std::random_device seed_gem;
//メルセンヌ・ツイスター
std::mt19937_64 engine(seed_gem());
//乱数範囲（ダイス用）
std::uniform_int_distribution<int> diceDist(1, 6);

typedef void (*PFunc[2])(int);

// 選んだのは奇数か偶数か
void CallBackOddOrEven(int num) {
	if (num % 2 == 1) {
		printf("半(奇数)\n");
	}
	else if (num % 2 == 0) {
		printf("丁(偶数)\n");
	}
}

// 答えは丁か半か
void CallBackAnswer(int num) {
	// ダイス
	int dice1 = diceDist(engine);
	int dice2 = diceDist(engine);
	int total = dice1 + dice2;

	// 出目
	if (total % 2 == 1) {
		printf("出目は...(%d, %d)の半\n", dice1, dice2);
	}
	else if (total % 2 == 0) {
		printf("出目は...(%d, %d)の丁\n", dice1, dice2);
	}

	// 勝ち負け
	if (total % 2 == num % 2) {
		printf("勝ち!\n");
	}
	else {
		printf("負け...\n");
	}
}

void DiceGame(PFunc p, int num, int second) {
	p[0](num);
	Sleep(second * 1000);
	p[1](num);
}

int main() {
	printf("start\n");
	printf("半(奇数)なら奇数、丁(偶数)なら偶数を入力してください\n");

	// 変数宣言
	int num;
	PFunc p;

	// 関数代入
	p[0] = &CallBackOddOrEven;
	p[1] = &CallBackAnswer;

	// 入力受付
	scanf_s("%d", &num);

	DiceGame(p, num, 3);

	return 0;
}