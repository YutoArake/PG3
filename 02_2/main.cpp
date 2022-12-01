#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [手順1] 単方向リストの構造体の定義
typedef struct cell {
	char namestr[32];			// 氏名
	char loanDateStr[9];		// 貸出日 YYYY/MM/DD
	char returnDateStr[9];	// 返却日 YYYY/MM/DD
	struct cell* next;
} CELL;

// コマンド
typedef enum COMMAND {
	NONE,		// 何もしない
	RECORD,	// 記録(貸出)
	SHOW,		// 閲覧
	RETURN,	// 返却
};

// 関数プロトタイプ宣言

/// <summary>
/// データを追加する関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
/// <param name="buf">挿入する値</param>
void WriteRecord(CELL* cell, const char* buf1, const char* buf2, const char* buf3);

/// <summary>
/// データを追加する関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
/// <param name="buf">挿入する値</param>
void Create(CELL* cell, const char* buf1, const char* buf2, const char* buf3);

/// <summary>
/// 一覧を表示する関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
void ShowIndex(CELL* cell);

int main() {
	// データ用変数
	char name[32];
	char loanDate[9];
	char returnDate[9];
	// [手順2] 先頭のセルの宣言
	CELL head;
	head.next = nullptr;

	// コマンド
	COMMAND command = NONE;

	// ループ
	while (true) {
		// コマンド選択
		printf("行動を数字で選択してください\n");
		printf("1:貸出 2:閲覧 3:返却\n\n");
		scanf_s("%d", &command);

		switch (command)
		{
		case RECORD:
			// セルに追加する情報を書き込む
			WriteRecord(&head, name, loanDate, returnDate);
			break;
		case SHOW:
			// [手順4] リスト一覧の表示
			ShowIndex(&head);
			break;
		case RETURN:
			printf("まだこの機能はないよ\n\n");
			break;
		}
	}

	return 0;
}

// 関数定義

void WriteRecord(CELL* cell, const char* buf1, const char* buf2, const char* buf3) {
	// 書き始め
	printf("-PG図書館貸出カード-\n");

	// 名前入力
	printf("名前を入力してください。(例 : 新家悠斗 )\n");
	scanf_s("%s", buf1, 32);

	// 貸出日入力
	printf("貸出日(今日の日付)を入力してください。(例 : YYYYMMDD)\n");
	scanf_s("%s", buf2, 9);

	// 返却日入力
	printf("返却日(今日の日付から2週間後)を入力してください。(例 : YYYYMMDD)\n");
	scanf_s("%s", buf3, 9);
	printf("\n");

	// [手順3] 最後尾にセルを追加
	Create(cell, buf1, buf2, buf3);
}

void Create(CELL* cell, const char* buf1, const char* buf2, const char* buf3) {
	CELL* newCell;	// 新規作成するセル
	// 新規作成する分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	// 新規作成するセルにデータを代入する
	// newCellのstrの中身へコピーする(アドレスを渡さないで)
	strcpy_s(newCell->namestr, 32, buf1);
	strcpy_s(newCell->loanDateStr, 9, buf2);
	strcpy_s(newCell->returnDateStr, 9, buf3);
	newCell->next = nullptr;

	// 最後(最新)のセルのアドレスの1つ目の処理は引数から持ってきた
	// リストのうち最初のセルのアドレスが該当する
	while (cell->next != nullptr) {
		// 最後尾のセルを検索する
		cell = cell->next;
	}

	// 最後尾のセルに次のセルのアドレスを渡す
	cell->next = newCell;
}

void ShowIndex(CELL* cell) {
	int num = 1;
	// // 最後尾のセルになるまで続く
	while (cell->next != nullptr) {
		// 人数
		printf("%d人目\n", num);
		num++;
		// 次のセルへ
		cell = cell->next;
		// セルの中身を表示
		printf("氏名：%s\n", cell->namestr);
		printf("貸出日：%s\n", cell->loanDateStr);
		printf("返却日：%s\n\n", cell->returnDateStr);
	}
}