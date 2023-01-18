#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

// �萔
const int WORDCOUNT = 32;

// �o�������X�g�̍\����
typedef struct cell {
	char str[WORDCOUNT];			// ������
	struct cell* prev;	// �O�̃Z��
	struct cell* next;	// ���̃Z��
} CELL;

// �R�}���h
typedef enum COMMAND {
	NONE,		// �������Ȃ�
	SHOW,		// �\��
	INSERT,		// �}��
	EDIT,		// �ҏW
	ERASE,		// �폜
	SORT,		// ���ёւ�
	BACK = 9,	// �߂�
};

// �֐��v���g�^�C�v�錾

// �ꗗ��\������֐�
void ShowIndex(CELL* cell);
// �w�肵���v�f�����\������֐�
void ShowIndex(CELL* cell, int itr);
// �C�ӂ̃Z���̃A�h���X��Ԃ��֐�
CELL* GetInsertCellAddress(CELL* cell, int itr);
// �Z����}������
void InsertCell(CELL* currentCell, const char* buf);
// �Z���̃��X�g��ҏW����
void EditCell(CELL* cell, int itr, const char* buf);

int main() {
	// ���X�g�p�ϐ��錾
	int iterator;	// �C�e���[�^
	char inputStr[WORDCOUNT];		// �}�����镶����
	CELL* insertCell;					// �}������Z��

	// �擪�̃Z���̐錾
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	// �R�}���h
	COMMAND command = NONE;

	while (true) {
		// �R�}���h�I��
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");
		printf("3.�v�f�̕ҏW\n");
		// �v�f��0�̂Ƃ��͔�\��
		if (head.next != nullptr) {
			printf("4.�v�f�̍폜\n");
			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
		}
		// ���s
		printf("\n");
		printf("------------------------------------------\n");
		printf("����𐔎��őI�����Ă�������\n");
		scanf_s("%d", &command);	// ����

		switch (command)
		{
		case SHOW:
			while (true) {
				// �R�}���h�I��
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				// ���s
				printf("\n");
				printf("����𐔎��őI�����Ă�������\n");
				scanf_s("%d", &command);	// ����

				// �v�f�̈ꗗ�\��
				if (command == 1) {
					// �ꗗ
					ShowIndex(&head);

					// ���̑�������
					scanf_s("%d", &command);

					// 1�Ȃ�continue�A2�Ȃ�break����
					if (command == 1) {
						continue;
					}
					else if (command == 2) {
						break;
					}

				}
				// ���Ԃ��w�肵�ėv�f��\��
				else if (command == 2) {
					// �w�肵���v�f��\��
					ShowIndex(&head, iterator);

					// ���̑�������
					scanf_s("%d", &command);	// ����

					// 1�Ȃ�continue�A2�Ȃ�break����
					if (command == 1) {
						continue;
					}
					else if (command == 2) {
						break;
					}

				}
				// �v�f����ɖ߂�
				else if (command == 9) {
					break;
				}
			}
			break;

		case INSERT:
			printf("[���X�g�v�f�̒ǉ�]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ��0����͂��Ă��������B\n");
			printf("�����݂̃Z���̑��������傫���l�̏ꍇ���Ō���ɒǉ����܂��B\n");
			scanf_s("%d", &iterator);
			printf("\n");
			printf("�ǉ�����v�f�̒l(����)����͂��Ă�������\n");
			scanf_s("%s", inputStr, WORDCOUNT);
			printf("\n");

			// �C�e���[�^��0��������
			if (iterator == 0) iterator = 99;

			// �}������Z���̃A�h���X���擾
			insertCell = GetInsertCellAddress(&head, iterator);
			// �Z����}��
			InsertCell(insertCell, inputStr);

			// �m�F
			printf("�v�f�h%s�h��%d�Ԗڂɑ}������܂���\n", inputStr, iterator);
			break;

		case EDIT:
			// �ҏW
			EditCell(&head, iterator, inputStr);
			break;

		case ERASE:
			printf("[�v�f�̍폜]\n");
			printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator);
			printf("\n");
			printf("�Ԗڂ̗v�f�h�h���폜���܂����B\n");

			printf("�Ԗڂ̗v�f��������܂���ł����B\n");
			break;
		case SORT:
			break;
		default:
			break;
		}

		// ���s
		printf("\n");
	}

	return 0;
}

// �֐���`
void ShowIndex(CELL* cell) {
	int num = 0;

	printf("[�v�f�̈ꗗ�\��]\n");
	printf("�v�f�ꗗ : {\n");

	// // �Ō���̃Z���ɂȂ�܂ő���
	while (cell->next != nullptr) {
		printf("%d:�h%s�h\n", num, cell->str);
		num++;
	}

	printf("}\n");
	printf("\n");
	// �v�f��
	printf("�v�f��:%d\n", ++num);
	printf("\n");
	printf("------------------------------------------\n");
	printf("1.�v�f�̕\���ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
}

void ShowIndex(CELL* cell, int itr) {
	printf("[���Ԃ��w�肵�ėv�f��\��]\n");
	printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B�Ō���̏ꍇ��0����͂��Ă��������B\n");
	printf("�����݂̃Z���̑��������傫���l�̏ꍇ���Ō���ɂ��܂��B\n");
	scanf_s("%d", &itr);	// ����
	printf("\n");
	// �w�肵���Z���̃A�h���X���擾
	CELL* selectCell = GetInsertCellAddress(cell, itr);
	// �\��
	printf("%d:%s", itr, selectCell->str);

	printf("\n");
	printf("------------------------------------------\n");
	printf("1.�v�f�̕\���ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
}

CELL* GetInsertCellAddress(CELL* cell, int itr) {
	for (int i = 0; i < itr; i++) {
		if (cell->next != nullptr) {
			cell = cell->next;
		}
		else {	// �Z���̑������������C�e���[�^�̒l�������烋�[�v�𔲂���
			break;
		}
	}
	return cell;
}

void InsertCell(CELL* currentCell, const char* buf) {
	CELL* newCell;	// �V�K�쐬����Z��
	// �V�K�쐬���镪�̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	// �V�K�쐬����Z���Ƀf�[�^��������
	newCell->prev = currentCell;
	newCell->next = nullptr;
	// newCell��str�̒��g�փR�s�[����(�A�h���X��n���Ȃ���)
	strcpy_s(newCell->str, WORDCOUNT, buf);

	// �I�������Z���Ɏ��̃A�h���X�������Ă����
	if (currentCell->next != nullptr) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
		newCell->next = nextCell;
	}

	// ���݂̃Z���Ɏ��̃Z���̃A�h���X��n��
	currentCell->next = newCell;
}

void EditCell(CELL* cell, int itr, const char* buf) {
	int num = 0;
	CELL* cellNum = cell;

	for (int i = 0; i < itr; i++) {
		if (cellNum->next != nullptr) {
			cellNum = cellNum->next;
			num++;
		}
		else {	// �Z���̑������������C�e���[�^�̒l�������烋�[�v�𔲂���
			break;
		}
	}

	printf("[�v�f�̕ҏW]\n");
	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
	scanf_s("%d", &itr);
	printf("\n");

	if (itr > 0 && itr <= num) {
		printf("%d�Ԗڂ̗v�f�̕ύX����l(����)����͂��Ă��������B\n", itr);
		scanf_s("%s", buf, WORDCOUNT);
		printf("\n");
		// �w�肵���Z���̃A�h���X���擾
		CELL* selectCell = GetInsertCellAddress(cell, itr);
		printf("%d�Ԗڂ̗v�f�̒l(����)���h%s�h�ɕύX����܂����B\n", itr, buf);
	}
	else {
		printf("�Ԗڂ̗v�f��������܂���ł����B\n");
	}
}