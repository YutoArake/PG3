#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// コマンド
typedef enum COMMAND {
	NONE,		// 何もしない
	SHOW,		// 表示
	INSERT,		// 挿入
	EDIT,		// 編集
	ERASE,		// 削除
};


int main() {


	while (true) {
		// コマンド選択
		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		printf("3.要素の編集\n");
		// 要素が0個のときは非表示
		printf("4.要素の削除\n");
		printf("5.要素の並び替え(オプション)\n");
		// 改行
		printf("\n");
		printf("------------------------------------------\n");
		printf("操作を数字で選択してください\n");

		scanf_s("%d", )
	}

	return 0;
}