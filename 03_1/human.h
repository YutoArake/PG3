#pragma once

class Human {
public:
	// �R���X�g���N�^
	Human(const char* name);
	// �f�X�g���N�^
	~Human();
	// �R�s�[�R���X�g���N�^
	Human(const Human& obj);

private:
	const char* name;
};