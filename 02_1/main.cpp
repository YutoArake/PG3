#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int main() {
	// 年代リスト
	list<int> yearList = { 1970, 1971, 2019, 2020, 2022 };

	// 駅リスト(山手線)
	list<const char*> stationList = {
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	// 駅番号(JY)
	int stationNum;

	for (list<int>::iterator itr_y = yearList.begin(); itr_y != yearList.end(); ++itr_y)
	{
		// 駅番号(JY 01から)
		stationNum = 1;

		// 1971年と2020年は省く
		if (*itr_y != 1971 && *itr_y != 2020) {
			// 年代ごとの駅表
			cout << *itr_y << " 年の山手線の駅一覧(内回り)" << endl;
		}

		for (list<const char*>::iterator itr_s = stationList.begin(); itr_s != stationList.end(); ++itr_s)
		{
			if (*itr_y == 1971 && *itr_s == "Tabata") {
				// 西日暮里を挿入
				itr_s = stationList.insert(itr_s, "Nishi-Nippori");
				break;
			}
			else if (*itr_y == 2020 && *itr_s == "Tamachi") {
				// 高輪ゲートウェイを挿入
				itr_s = stationList.insert(itr_s, "Takanawa Gateway");
				break;
			}

			// 1971年と2020年は省く
			if (*itr_y != 1971 && *itr_y != 2020) {
				// イテレータの要素番号の中身を表示
				cout << "JY " << stationNum << " : " << *itr_s << endl;
			}

			// 駅番号をインクリメント
			stationNum++;
		}
		// 改行
		cout << endl;
	}

	return 0;
}