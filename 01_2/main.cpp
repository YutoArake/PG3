#include<stdio.h>

// �K��
int Recursive(int n) {
	if (n <= 1) {
		return (1);
	}

	return (n * Recursive(n - 1));
}

// �����v�Z
int HourlyWageCalc(int hour) {
	if (hour == 1) {
		return 100;
	}

	return (HourlyWageCalc(hour - 1) * 2) - 50;
}

int main() {
	int hour = 6;		// ����������
	int result;			// �v�Z����

	result = HourlyWageCalc(hour);
	printf("���������� : %d���Ԗ� = %d�~\n", hour, result);

	return 0;
}