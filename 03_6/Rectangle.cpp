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
	printf("ñ êœÇÕ %f\n", size);
}
