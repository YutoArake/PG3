#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public: // �����o�֐�
	// �R���X�g���N�^
	Rectangle(float height, float width);
	// �ʐόv�Z
	void Size() override;
	// �v�Z����
	void Draw() override;

private: // �����o�ϐ�
	// �c
	float height;
	// ��
	float width;
	// �ʐ�
	float size;
};