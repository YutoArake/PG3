#include "human.h"
#include <stdio.h>

Human::Human(const char* name) {
	printf("%s\n", name);

	// ���O���R�s�[
	this->name = name;
}
Human::~Human(){}

Human::Human(const Human& obj) {
	printf("%s���R�s�[���܂�\n", obj.name);

	// ���O���R�s�[
	name = obj.name;
}