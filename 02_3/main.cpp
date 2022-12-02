#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [手順1] 双方向リストの構造体の定義
typedef struct cell {
	int val;
	struct cell* prev;
	struct cell* next;
} CELL;

// 関数プロトタイプ宣言

/// <summary>
/// データを追加する関数
/// </summary>
/// <param name="currentCell">リストの現在のセル</param>
/// <param name="buf">挿入する値</param>
void Create(CELL* currentCell, int val);

/// <summary>
/// 一覧を表示する関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
void Index(CELL* cell);

/// <summary>
/// 任意のセルのアドレスを返す関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
/// <param name="itr">イテレータ</param>
CELL* GetInsertCellAddress(CELL* cell, int itr);

int main() {
	// データ用変数
	int iterator;
	int inputValue;
	CELL* insertCell;
	
	// [手順2] 先頭のセルの宣言
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	// コマンド
	//COMMAND command = NONE;

	// ループ
	while (true) {
		printf("何番目のセルの後ろに挿入してますか？\n");
		scanf_s("%d", &iterator);

		printf("挿入する値を入力してください？\n");
		scanf_s("%d", &inputValue);

		// [手順3] 任意のセルの後ろに追加
		insertCell = GetInsertCellAddress(&head, iterator);	// 挿入したいセルのアドレスを取得 
		Create(insertCell, inputValue);		// セルの追加

		// [手順4] リスト一覧の表示
		Index(&head);
	}

	return 0;
}

// 関数定義

void Create(CELL* currentCell, int val) {
	CELL* newCell;	// 新規作成するセル
	// 新規作成する分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	// 新規作成するセルにデータを代入する
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// 次のセルの前のアドレスを書き換える
	CELL* nextCell = currentCell->next;
	nextCell->prev = newCell;

	// 現在のセルに次のセルのアドレスを渡す
	currentCell->next = newCell;
}

void Index(CELL* cell) {
	int num = 1;
	// // 最後尾のセルになるまで続く
	while (cell->next != nullptr) {
		// 次のセルへ
		cell = cell->next;
		printf("%d", num);
		// セルの中身を表示
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
		else {	// セルの総数よりも多いイテレータの値だったらループを抜ける
			break;
		}
	}
	return cell;
}