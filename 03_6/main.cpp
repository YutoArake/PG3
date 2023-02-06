#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
	// �錾
	float radius = 2.0f;
	float height = 3.0f;
	float width = 5.0f;
	IShape* circle = new Circle(radius);
	IShape* rectangle = new Rectangle(height, width);

	// �v�Z
	circle->Size();
	rectangle->Size();

	// ���ʏo��
	circle->Draw();
	rectangle->Draw();

	// ���
	delete circle;
	delete rectangle;

	return 0;
}