#include <stdio.h>

int func(int n);

int main() {
	int data;

	printf("data : ");
	scanf_s("%d", &data);

	printf("%d != %d\n", data, func(data));

	return 0;
}

int func(int n) {
	if (n == 1) {
		return 1;
	} else {
		return func(n - 1) * n;
	}
}