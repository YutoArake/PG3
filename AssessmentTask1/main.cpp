#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

// 定数
const int WORDCOUNT = 32;

// 双方向リストの構造体
typedef struct cell {
	char str[WORDCOUNT];			// 文字列
	struct cell* prev;	// 前のセル
	struct cell* next;	// 次のセル
} CELL;

// コマンド
typedef enum COMMAND {
	NONE,		// 何もしない
	SHOW,		// 表示
	INSERT,		// 挿入
	EDIT,		// 編集
	ERASE,		// 削除
	SORT,		// 並び替え
	BACK = 9,	// 戻る
};

// 関数プロトタイプ宣言

// 一覧を表示する関数
void ShowIndex(CELL* cell);
// 指定した要素だけ表示する関数
void ShowIndex(CELL* cell, int itr);
// 任意のセルのアドレスを返す関数
CELL* GetInsertCellAddress(CELL* cell, int itr);
// セルを挿入する
void InsertCell(CELL* currentCell, const char* buf);
// セルのリストを編集する
void EditCell(CELL* cell, int itr, const char* buf);

int main() {
	// リスト用変数宣言
	int iterator;	// イテレータ
	char inputStr[WORDCOUNT];		// 挿入する文字列
	CELL* insertCell;					// 挿入するセル

	// 先頭のセルの宣言
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	// コマンド
	COMMAND command = NONE;

	while (true) {
		// コマンド選択
		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		printf("3.要素の編集\n");
		// 要素が0個のときは非表示
		if (head.next != nullptr) {
			printf("4.要素の削除\n");
			printf("5.要素の並び替え(オプション)\n");
		}
		// 改行
		printf("\n");
		printf("------------------------------------------\n");
		printf("操作を数字で選択してください\n");
		scanf_s("%d", &command);	// 入力

		switch (command)
		{
		case SHOW:
			while (true) {
				// コマンド選択
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				// 改行
				printf("\n");
				printf("操作を数字で選択してください\n");
				scanf_s("%d", &command);	// 入力

				// 要素の一覧表示
				if (command == 1) {
					// 一覧
					ShowIndex(&head);

					// 次の操作を入力
					scanf_s("%d", &command);

					// 1ならcontinue、2ならbreakする
					if (command == 1) {
						continue;
					}
					else if (command == 2) {
						break;
					}

				}
				// 順番を指定して要素を表示
				else if (command == 2) {
					// 指定した要素を表示
					ShowIndex(&head, iterator);

					// 次の操作を入力
					scanf_s("%d", &command);	// 入力

					// 1ならcontinue、2ならbreakする
					if (command == 1) {
						continue;
					}
					else if (command == 2) {
						break;
					}

				}
				// 要素操作に戻る
				else if (command == 9) {
					break;
				}
			}
			break;

		case INSERT:
			printf("[リスト要素の追加]\n");
			printf("要素を追加する場所を指定してください。最後尾に追加する場合は0を入力してください。\n");
			printf("※現在のセルの総数よりも大きい値の場合も最後尾に追加します。\n");
			scanf_s("%d", &iterator);
			printf("\n");
			printf("追加する要素の値(文字)を入力してください\n");
			scanf_s("%s", inputStr, WORDCOUNT);
			printf("\n");

			// イテレータが0だったら
			if (iterator == 0) iterator = 99;

			// 挿入するセルのアドレスを取得
			insertCell = GetInsertCellAddress(&head, iterator);
			// セルを挿入
			InsertCell(insertCell, inputStr);

			// 確認
			printf("要素”%s”が%d番目に挿入されました\n", inputStr, iterator);
			break;

		case EDIT:
			// 編集
			EditCell(&head, iterator, inputStr);
			break;

		case ERASE:
			printf("[要素の削除]\n");
			printf("削除したい要素の番号を指定してください。\n");
			scanf_s("%d", &iterator);
			printf("\n");
			printf("番目の要素””を削除しました。\n");

			printf("番目の要素が見つかりませんでした。\n");
			break;
		case SORT:
			break;
		default:
			break;
		}

		// 改行
		printf("\n");
	}

	return 0;
}

// 関数定義
void ShowIndex(CELL* cell) {
	int num = 0;

	printf("[要素の一覧表示]\n");
	printf("要素一覧 : {\n");

	// // 最後尾のセルになるまで続く
	while (cell->next != nullptr) {
		printf("%d:”%s”\n", num, cell->str);
		num++;
	}

	printf("}\n");
	printf("\n");
	// 要素数
	printf("要素数:%d\n", ++num);
	printf("\n");
	printf("------------------------------------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
}

void ShowIndex(CELL* cell, int itr) {
	printf("[順番を指定して要素を表示]\n");
	printf("表示したい要素の順番を指定してください。最後尾の場合は0を入力してください。\n");
	printf("※現在のセルの総数よりも大きい値の場合も最後尾にします。\n");
	scanf_s("%d", &itr);	// 入力
	printf("\n");
	// 指定したセルのアドレスを取得
	CELL* selectCell = GetInsertCellAddress(cell, itr);
	// 表示
	printf("%d:%s", itr, selectCell->str);

	printf("\n");
	printf("------------------------------------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
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

void InsertCell(CELL* currentCell, const char* buf) {
	CELL* newCell;	// 新規作成するセル
	// 新規作成する分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	// 新規作成するセルにデータを代入する
	newCell->prev = currentCell;
	newCell->next = nullptr;
	// newCellのstrの中身へコピーする(アドレスを渡さないで)
	strcpy_s(newCell->str, WORDCOUNT, buf);

	// 選択したセルに次のアドレスが入っていれば
	if (currentCell->next != nullptr) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
		newCell->next = nextCell;
	}

	// 現在のセルに次のセルのアドレスを渡す
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
		else {	// セルの総数よりも多いイテレータの値だったらループを抜ける
			break;
		}
	}

	printf("[要素の編集]\n");
	printf("編集したい要素の番号を指定してください。\n");
	scanf_s("%d", &itr);
	printf("\n");

	if (itr > 0 && itr <= num) {
		printf("%d番目の要素の変更する値(文字)を入力してください。\n", itr);
		scanf_s("%s", buf, WORDCOUNT);
		printf("\n");
		// 指定したセルのアドレスを取得
		CELL* selectCell = GetInsertCellAddress(cell, itr);
		printf("%d番目の要素の値(文字)が”%s”に変更されました。\n", itr, buf);
	}
	else {
		printf("番目の要素が見つかりませんでした。\n");
	}
}