#include "Circle.h"
#include <stdio.h>

Circle::Circle(float radius) {
	this->radius = radius;
}

void Circle::Size() {
	size = radius * radius * 3.14;
}

void Circle::Draw() {
	printf("ñ êœÇÕ %f\n", size);
}
