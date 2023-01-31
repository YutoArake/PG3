#include "human.h"
#include <stdio.h>

Human::Human(const char* name) {
	printf("%s\n", name);

	// 名前をコピー
	this->name = name;
}
Human::~Human(){}

Human::Human(const Human& obj) {
	printf("%sをコピーします\n", obj.name);

	// 名前をコピー
	name = obj.name;
}