#pragma once
#include "IShape.h"

class Circle : public IShape {
public: // �����o�֐�
	// �R���X�g���N�^
	Circle(float radius);
	// �ʐόv�Z
	void Size() override;
	// �v�Z����
	void Draw() override;

private: // �����o�ϐ�
	// ���a
	float radius;
	// �ʐ�
	float size;
};