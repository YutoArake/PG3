#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [�菇1] �o�������X�g�̍\���̂̒�`
typedef struct cell {
	char station[32];
	struct cell* prev;
	struct cell* next;
} CELL;

// �֐��v���g�^�C�v�錾

/// <summary>
/// �f�[�^��ǉ�����֐�
/// </summary>
/// <param name="currentCell">���X�g�̌��݂̃Z��</param>
/// <param name="buf">�}������l</param>
void Create(CELL* currentCell, const char* buf);

/// <summary>
/// �ꗗ��\������֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
void Index(CELL* cell, int cmd);

/// <summary>
/// �C�ӂ̃Z���̃A�h���X��Ԃ��֐�
/// </summary>
/// <param name="cell">���X�g�̍ŏ��̃Z��</param>
/// <param name="itr">�C�e���[�^</param>
CELL* GetInsertCellAddress(CELL* cell, int itr);

int main() {
	// �}������Z��
	char station[32];
	int iterator;
	CELL* insertCell;
	
	// �擪�̃Z���̐錾
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;
	
	// �w�ꗗ
	const int STATION_NUM = 47;
	const char* stationList[STATION_NUM] = {
		"��D", "�{����", "�`���", "�m����", "�V���c",
		"��q", "����", "�R��", "�ΐ쒬", "�֓�",
		"���ؒ�", "���l", "���_�ސ�", "�V�q��", "�ߌ�",
		"���", "���c", "��X", "��䒬", "�i��",
		"���փQ�[�g�E�F�C", "�c��", "�l����", "�V��", "�L�y��",
		"����", "�_�c", "�H�t��", "��k��", "���",
		"��J", "���闢", "�����闢", "�c�[", "�㒆��",
		"���q", "���\��", "�ԉH", "���", "�����",
		"�n", "��Y�a", "�Y�a", "�k�Y�a", "�^��",
		"�������ܐV�s�S", "��{"
	};

	// ���փQ�[�g�E�F�C�ȊO�̉w���Z���ɑ}��
	for (int itr = 0; itr < STATION_NUM; itr++) {
		if (itr != 20) {
			insertCell = GetInsertCellAddress(&head, itr);	// �}���������Z���̃A�h���X���擾 
			strcpy_s(station, 32, stationList[itr]);	// �w�����R�s�[
			Create(insertCell, station);				// �Z���̒ǉ�
		}
	}

	// �I����
	int command = 0;

	// ���[�v
	while (true) {
		printf("[���l���k���w�ꗗ]\n");
		printf("���փQ�[�g�E�F�C���ǉ������O���ォ\n");
		printf("�O : 1�A�� : 2\n");
		scanf_s("%d", &command);
		printf("\n");

		// ���փQ�[�g�E�F�C��ǉ�
		if (command == 2) {
			iterator = 20;
			// [�菇3] �C�ӂ̃Z���̌��ɒǉ�
			insertCell = GetInsertCellAddress(&head, iterator);	// �}���������Z���̃A�h���X���擾 
			strcpy_s(station, 32, stationList[iterator]);	// �w�����R�s�[
			Create(insertCell, station);							// �Z���̒ǉ�
		}
		
		printf("�ꗗ���鏇�Ԃ����߂Ă�������\n");
		printf("�k�s : 1�A��s : 2\n");
		scanf_s("%d", &command);

		// [�菇4] ���X�g�ꗗ�̕\��
		Index(&head, command);
		printf("\n");
	}

	return 0;
}

// �֐���`

void Create(CELL* currentCell, const char* buf) {
	CELL* newCell;	// �V�K�쐬����Z��
	// �V�K�쐬���镪�̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	// �V�K�쐬����Z���Ƀf�[�^��������
	strcpy_s(newCell->station, 32, buf);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// ���̃Z���̑O�̃A�h���X������������
	if (currentCell->next != nullptr) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	// ���݂̃Z���Ɏ��̃Z���̃A�h���X��n��
	currentCell->next = newCell;
}

void Index(CELL* cell, int cmd) {
	// // �Ō���̃Z���ɂȂ�܂ő���
	if (cmd == 1) {
		int num = 1;
		while (cell->next != nullptr) {
			// ���̃Z����
			cell = cell->next;
			printf("JK ");
			printf("%2d : ", num);
			// �Z���̒��g��\��
			printf("%s", cell->station);
			printf("\n");
			num++;
		}
	}
	else if (cmd == 2) {
		int num = 47;
		cell = GetInsertCellAddress(cell, num);
		while (cell->prev != nullptr) {
			printf("JK ");
			printf("%2d : ", num);
			// �Z���̒��g��\��
			printf("%s", cell->station);
			printf("\n");
			// ���̃Z����
			cell = cell->prev;
			num--;
		}
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