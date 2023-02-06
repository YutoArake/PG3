#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle(float height, float width) {
	this->height = height;
	this->width = width;
}

void Rectangle::Size() {
	size = height * width;
}

void Rectangle::Draw() {
	printf("�ʐς� %f\n", size);
}
