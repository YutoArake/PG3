#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [�菇1] �o�������X�g�̍\���̂̒�`
typedef struct cell {
	int val;
	struct cell* prev;
	struct cell* next;
} CELL;

// �֐��v���g�^�C�v�錾

/// <summary>
/// �f�[�^��ǉ�����֐�
/// </summary>
/// <param name="currentCell">���X�g�̌��݂̃Z��</param>
/// <param name="buf">�}������l</param>
void Create(CELL* currentCell, int val);

/// <summary>
/// �ꗗ��\������֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
void Index(CELL* cell);

/// <summary>
/// �C�ӂ̃Z���̃A�h���X��Ԃ��֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
/// <param name="itr">�C�e���[�^</param>
CELL* GetInsertCellAddress(CELL* cell, int itr);

int main() {
	// �f�[�^�p�ϐ�
	int iterator;
	int inputValue;
	CELL* insertCell;
	
	// [�菇2] �擪�̃Z���̐錾
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	// �R�}���h
	//COMMAND command = NONE;

	// ���[�v
	while (true) {
		printf("���Ԗڂ̃Z���̌��ɑ}�����Ă܂����H\n");
		scanf_s("%d", &iterator);

		printf("�}������l����͂��Ă��������H\n");
		scanf_s("%d", &inputValue);

		// [�菇3] �C�ӂ̃Z���̌��ɒǉ�
		insertCell = GetInsertCellAddress(&head, iterator);	// �}���������Z���̃A�h���X���擾 
		Create(insertCell, inputValue);		// �Z���̒ǉ�

		// [�菇4] ���X�g�ꗗ�̕\��
		Index(&head);
	}

	return 0;
}

// �֐���`

void Create(CELL* currentCell, int val) {
	CELL* newCell;	// �V�K�쐬����Z��
	// �V�K�쐬���镪�̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	// �V�K�쐬����Z���Ƀf�[�^��������
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// ���̃Z���̑O�̃A�h���X������������
	CELL* nextCell = currentCell->next;
	nextCell->prev = newCell;

	// ���݂̃Z���Ɏ��̃Z���̃A�h���X��n��
	currentCell->next = newCell;
}

void Index(CELL* cell) {
	int num = 1;
	// // �Ō���̃Z���ɂȂ�܂ő���
	while (cell->next != nullptr) {
		// ���̃Z����
		cell = cell->next;
		printf("%d", num);
		// �Z���̒��g��\��
		printf("%p", cell->prev);
		printf("%5d", cell->val);
		printf("(%p)", cell);
		printf("%p\n", cell->next);

		num++;
	}
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