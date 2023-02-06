#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
	// éŒ¾
	float radius = 2.0f;
	float height = 3.0f;
	float width = 5.0f;
	IShape* circle = new Circle(radius);
	IShape* rectangle = new Rectangle(height, width);

	// ŒvŽZ
	circle->Size();
	rectangle->Size();

	// Œ‹‰Êo—Í
	circle->Draw();
	rectangle->Draw();

	// ‰ð•ú
	delete circle;
	delete rectangle;

	return 0;
}