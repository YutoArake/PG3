#include <stdio.h>
#include <Windows.h>
#include <random>

//�����V�[�h������
std::random_device seed_gem;
//�����Z���k�E�c�C�X�^�[
std::mt19937_64 engine(seed_gem());
//�����͈́i�_�C�X�p�j
std::uniform_int_distribution<int> diceDist(1, 6);

typedef void (*PFunc[2])(int);

// �I�񂾂̂͊��������
void CallBackOddOrEven(int num) {
	if (num % 2 == 1) {
		printf("��(�)\n");
	}
	else if (num % 2 == 0) {
		printf("��(����)\n");
	}
}

// �����͒�������
void CallBackAnswer(int num) {
	// �_�C�X
	int dice1 = diceDist(engine);
	int dice2 = diceDist(engine);
	int total = dice1 + dice2;

	// �o��
	if (total % 2 == 1) {
		printf("�o�ڂ�...(%d, %d)�̔�\n", dice1, dice2);
	}
	else if (total % 2 == 0) {
		printf("�o�ڂ�...(%d, %d)�̒�\n", dice1, dice2);
	}

	// ��������
	if (total % 2 == num % 2) {
		printf("����!\n");
	}
	else {
		printf("����...\n");
	}
}

void DiceGame(PFunc p, int num, int second) {
	p[0](num);
	Sleep(second * 1000);
	p[1](num);
}

int main() {
	printf("start\n");
	printf("��(�)�Ȃ��A��(����)�Ȃ��������͂��Ă�������\n");

	// �ϐ��錾
	int num;
	PFunc p;

	// �֐����
	p[0] = &CallBackOddOrEven;
	p[1] = &CallBackAnswer;

	// ���͎�t
	scanf_s("%d", &num);

	DiceGame(p, num, 3);

	return 0;
}