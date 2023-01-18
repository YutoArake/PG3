#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [手順1] 双方向リストの構造体の定義
typedef struct cell {
	char station[32];
	struct cell* prev;
	struct cell* next;
} CELL;

// 関数プロトタイプ宣言

/// <summary>
/// データを追加する関数
/// </summary>
/// <param name="currentCell">リストの現在のセル</param>
/// <param name="buf">挿入する値</param>
void Create(CELL* currentCell, const char* buf);

/// <summary>
/// 一覧を表示する関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
void Index(CELL* cell, int cmd);

/// <summary>
/// 任意のセルのアドレスを返す関数
/// </summary>
/// <param name="cell">リストの最初のセル</param>
/// <param name="itr">イテレータ</param>
CELL* GetInsertCellAddress(CELL* cell, int itr);

int main() {
	// 挿入するセル
	char station[32];
	int iterator;
	CELL* insertCell;
	
	// 先頭のセルの宣言
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;
	
	// 駅一覧
	const int STATION_NUM = 47;
	const char* stationList[STATION_NUM] = {
		"大船", "本郷台", "港南台", "洋光台", "新杉田",
		"磯子", "根岸", "山手", "石川町", "関内",
		"桜木町", "横浜", "東神奈川", "新子安", "鶴見",
		"川崎", "蒲田", "大森", "大井町", "品川",
		"高輪ゲートウェイ", "田町", "浜松町", "新橋", "有楽町",
		"東京", "神田", "秋葉原", "御徒町", "上野",
		"鶯谷", "日暮里", "西日暮里", "田端", "上中里",
		"王子", "東十条", "赤羽", "川口", "西川口",
		"蕨", "南浦和", "浦和", "北浦和", "与野",
		"さいたま新都心", "大宮"
	};

	// 高輪ゲートウェイ以外の駅をセルに挿入
	for (int itr = 0; itr < STATION_NUM; itr++) {
		if (itr != 20) {
			insertCell = GetInsertCellAddress(&head, itr);	// 挿入したいセルのアドレスを取得 
			strcpy_s(station, 32, stationList[itr]);	// 駅名をコピー
			Create(insertCell, station);				// セルの追加
		}
	}

	// 選択肢
	int command = 0;

	// ループ
	while (true) {
		printf("[京浜東北線駅一覧]\n");
		printf("高輪ゲートウェイが追加される前か後か\n");
		printf("前 : 1、後 : 2\n");
		scanf_s("%d", &command);
		printf("\n");

		// 高輪ゲートウェイを追加
		if (command == 2) {
			iterator = 20;
			// [手順3] 任意のセルの後ろに追加
			insertCell = GetInsertCellAddress(&head, iterator);	// 挿入したいセルのアドレスを取得 
			strcpy_s(station, 32, stationList[iterator]);	// 駅名をコピー
			Create(insertCell, station);							// セルの追加
		}
		
		printf("一覧する順番を決めてください\n");
		printf("北行 : 1、南行 : 2\n");
		scanf_s("%d", &command);

		// [手順4] リスト一覧の表示
		Index(&head, command);
		printf("\n");
	}

	return 0;
}

// 関数定義

void Create(CELL* currentCell, const char* buf) {
	CELL* newCell;	// 新規作成するセル
	// 新規作成する分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	// 新規作成するセルにデータを代入する
	strcpy_s(newCell->station, 32, buf);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// 次のセルの前のアドレスを書き換える
	if (currentCell->next != nullptr) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	// 現在のセルに次のセルのアドレスを渡す
	currentCell->next = newCell;
}

void Index(CELL* cell, int cmd) {
	// // 最後尾のセルになるまで続く
	if (cmd == 1) {
		int num = 1;
		while (cell->next != nullptr) {
			// 次のセルへ
			cell = cell->next;
			printf("JK ");
			printf("%2d : ", num);
			// セルの中身を表示
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
			// セルの中身を表示
			printf("%s", cell->station);
			printf("\n");
			// 次のセルへ
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
		else {	// セルの総数よりも多いイテレータの値だったらループを抜ける
			break;
		}
	}
	return cell;
}