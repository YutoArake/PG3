#pragma once

class Sample {
private:
	int num;

public:
	// �R���X�g���N�^�����A�����h���Œ�`
	Sample(int x = 0) { num = x; }

	// ������Z�q�̃I�[�o�[���[�h�A����́Ah���Œ�`(�{����cpp��)
	Sample& operator=(const Sample& obj) {
		num = obj.num;
		return *this;
	}
};

