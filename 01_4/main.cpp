#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

//�����V�[�h������
std::random_device seed_gem;
//�����Z���k�E�c�C�X�^�[
std::mt19937_64 engine(seed_gem());
//�����͈́i�_�C�X�p�j
std::uniform_int_distribution<int> diceDist(1, 6);

int main(int argc, const char *argv[]) {
	// �񋓌^
	enum ResultNum {
		EVEN,		// ����
		ODD,			// �
		OTHER		// ����ȊO
	};

	// �ϐ��錾
	int dice1 = diceDist(engine);
	int dice2 = diceDist(engine);
	int num;

	// �����_��
	std::function<int()> addDiceNum = [&]() {return dice1 + dice2; };
	// ��Ȃ�1�A�����Ȃ�0�A����ȊO�Ȃ�-1��Ԃ�
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
		// �I�񂾂̂͊��������
		if (num % 2 == ODD) {
			printf("��(�)\n");
		}
		else if (num % 2 == EVEN) {
			printf("��(����)\n");
		}

		Sleep(3 * 1000);

		// �o��
		if (checkNum == ODD) {
			printf("�o�ڂ�...(%d, %d)�̔�\n", dice1, dice2);
		}
		else if (checkNum == EVEN) {
			printf("�o�ڂ�...(%d, %d)�̒�\n", dice1, dice2);
		}

		// ���s
		if (checkNum == num % 2) {
			printf("����!\n");
		}
		else {
			printf("����...\n");
		}
	};

	// ������o��
	printf("start\n");
	printf("��(�)�Ȃ��A��(����)�Ȃ��������͂��Ă�������\n");

	// ���͎�t
	scanf_s("%d", &num);

	print(checkNum(addDiceNum()));

	return 0;
}