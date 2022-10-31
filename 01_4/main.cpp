#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

//乱数シード生成器
std::random_device seed_gem;
//メルセンヌ・ツイスター
std::mt19937_64 engine(seed_gem());
//乱数範囲（ダイス用）
std::uniform_int_distribution<int> diceDist(1, 6);

int main(int argc, const char *argv[]) {
	// 列挙型
	enum ResultNum {
		EVEN,		// 偶数
		ODD,			// 奇数
		OTHER		// それ以外
	};

	// 変数宣言
	int dice1 = diceDist(engine);
	int dice2 = diceDist(engine);
	int num;

	// ラムダ式
	std::function<int()> addDiceNum = [&]() {return dice1 + dice2; };
	// 奇数なら1、偶数なら0、それ以外なら-1を返す
	std::function<int(int)> checkNum = [](int addDiceNum) {
		if (addDiceNum % 2 == 1) {
			return ODD;
		}
		else if (addDiceNum % 2 == 0) {
			return EVEN;
		}
		else {
			return OTHER;
		}
	};
	auto print = [&](int checkNum) {
		// 選んだのは奇数か偶数か
		if (num % 2 == ODD) {
			printf("半(奇数)\n");
		}
		else if (num % 2 == EVEN) {
			printf("丁(偶数)\n");
		}

		Sleep(3 * 1000);

		// 出目
		if (checkNum == ODD) {
			printf("出目は...(%d, %d)の半\n", dice1, dice2);
		}
		else if (checkNum == EVEN) {
			printf("出目は...(%d, %d)の丁\n", dice1, dice2);
		}

		// 勝敗
		if (checkNum == num % 2) {
			printf("勝ち!\n");
		}
		else {
			printf("負け...\n");
		}
	};

	// 文字列出力
	printf("start\n");
	printf("半(奇数)なら奇数、丁(偶数)なら偶数を入力してください\n");

	// 入力受付
	scanf_s("%d", &num);

	print(checkNum(addDiceNum()));

	return 0;
}