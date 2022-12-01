#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [�菇1] �P�������X�g�̍\���̂̒�`
typedef struct cell {
	char namestr[32];			// ����
	char loanDateStr[9];		// �ݏo�� YYYY/MM/DD
	char returnDateStr[9];	// �ԋp�� YYYY/MM/DD
	struct cell* next;
} CELL;

// �R�}���h
typedef enum COMMAND {
	NONE,		// �������Ȃ�
	RECORD,	// �L�^(�ݏo)
	SHOW,		// �{��
	RETURN,	// �ԋp
};

// �֐��v���g�^�C�v�錾

/// <summary>
/// �f�[�^��ǉ�����֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
/// <param name="buf">�}������l</param>
void WriteRecord(CELL* cell, const char* buf1, const char* buf2, const char* buf3);

/// <summary>
/// �f�[�^��ǉ�����֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
/// <param name="buf">�}������l</param>
void Create(CELL* cell, const char* buf1, const char* buf2, const char* buf3);

/// <summary>
/// �ꗗ��\������֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
void ShowIndex(CELL* cell);

int main() {
	// �f�[�^�p�ϐ�
	char name[32];
	char loanDate[9];
	char returnDate[9];
	// [�菇2] �擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;

	// �R�}���h
	COMMAND command = NONE;

	// ���[�v
	while (true) {
		// �R�}���h�I��
		printf("�s���𐔎��őI�����Ă�������\n");
		printf("1:�ݏo 2:�{�� 3:�ԋp\n\n");
		scanf_s("%d", &command);

		switch (command)
		{
		case RECORD:
			// �Z���ɒǉ����������������
			WriteRecord(&head, name, loanDate, returnDate);
			break;
		case SHOW:
			// [�菇4] ���X�g�ꗗ�̕\��
			ShowIndex(&head);
			break;
		case RETURN:
			printf("�܂����̋@�\�͂Ȃ���\n\n");
			break;
		}
	}

	return 0;
}

// �֐���`

void WriteRecord(CELL* cell, const char* buf1, const char* buf2, const char* buf3) {
	// �����n��
	printf("-PG�}���ّݏo�J�[�h-\n");

	// ���O����
	printf("���O����͂��Ă��������B(�� : �V�ƗI�l )\n");
	scanf_s("%s", buf1, 32);

	// �ݏo������
	printf("�ݏo��(�����̓��t)����͂��Ă��������B(�� : YYYYMMDD)\n");
	scanf_s("%s", buf2, 9);

	// �ԋp������
	printf("�ԋp��(�����̓��t����2�T�Ԍ�)����͂��Ă��������B(�� : YYYYMMDD)\n");
	scanf_s("%s", buf3, 9);
	printf("\n");

	// [�菇3] �Ō���ɃZ����ǉ�
	Create(cell, buf1, buf2, buf3);
}

void Create(CELL* cell, const char* buf1, const char* buf2, const char* buf3) {
	CELL* newCell;	// �V�K�쐬����Z��
	// �V�K�쐬���镪�̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	// �V�K�쐬����Z���Ƀf�[�^��������
	// newCell��str�̒��g�փR�s�[����(�A�h���X��n���Ȃ���)
	strcpy_s(newCell->namestr, 32, buf1);
	strcpy_s(newCell->loanDateStr, 9, buf2);
	strcpy_s(newCell->returnDateStr, 9, buf3);
	newCell->next = nullptr;

	// �Ō�(�ŐV)�̃Z���̃A�h���X��1�ڂ̏����͈������玝���Ă���
	// ���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (cell->next != nullptr) {
		// �Ō���̃Z������������
		cell = cell->next;
	}

	// �Ō���̃Z���Ɏ��̃Z���̃A�h���X��n��
	cell->next = newCell;
}

void ShowIndex(CELL* cell) {
	int num = 1;
	// // �Ō���̃Z���ɂȂ�܂ő���
	while (cell->next != nullptr) {
		// �l��
		printf("%d�l��\n", num);
		num++;
		// ���̃Z����
		cell = cell->next;
		// �Z���̒��g��\��
		printf("�����F%s\n", cell->namestr);
		printf("�ݏo���F%s\n", cell->loanDateStr);
		printf("�ԋp���F%s\n\n", cell->returnDateStr);
	}
}