#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int main() {
	// �N�ナ�X�g
	list<int> yearList = { 1970, 1971, 2019, 2020, 2022 };

	// �w���X�g(�R���)
	list<const char*> stationList = {
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	// �w�ԍ�(JY)
	int stationNum;

	for (list<int>::iterator itr_y = yearList.begin(); itr_y != yearList.end(); ++itr_y)
	{
		// �w�ԍ�(JY 01����)
		stationNum = 1;

		// 1971�N��2020�N�͏Ȃ�
		if (*itr_y != 1971 && *itr_y != 2020) {
			// �N�ゲ�Ƃ̉w�\
			cout << *itr_y << " �N�̎R����̉w�ꗗ(�����)" << endl;
		}

		for (list<const char*>::iterator itr_s = stationList.begin(); itr_s != stationList.end(); ++itr_s)
		{
			if (*itr_y == 1971 && *itr_s == "Tabata") {
				// �����闢��}��
				itr_s = stationList.insert(itr_s, "Nishi-Nippori");
				break;
			}
			else if (*itr_y == 2020 && *itr_s == "Tamachi") {
				// ���փQ�[�g�E�F�C��}��
				itr_s = stationList.insert(itr_s, "Takanawa Gateway");
				break;
			}

			// 1971�N��2020�N�͏Ȃ�
			if (*itr_y != 1971 && *itr_y != 2020) {
				// �C�e���[�^�̗v�f�ԍ��̒��g��\��
				cout << "JY " << stationNum << " : " << *itr_s << endl;
			}

			// �w�ԍ����C���N�������g
			stationNum++;
		}
		// ���s
		cout << endl;
	}

	return 0;
}