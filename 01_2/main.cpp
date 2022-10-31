#include<stdio.h>

// ŠKæ
int Recursive(int n) {
	if (n <= 1) {
		return (1);
	}

	return (n * Recursive(n - 1));
}

// ‹‹ŒvZ
int HourlyWageCalc(int hour) {
	if (hour == 1) {
		return 100;
	}

	return (HourlyWageCalc(hour - 1) * 2) - 50;
}

int main() {
	int hour = 6;		// “­‚¢‚½ŠÔ
	int result;			// ŒvZŒ‹‰Ê

	result = HourlyWageCalc(hour);
	printf("“­‚¢‚½ŠÔ : %dŠÔ–Ú = %d‰~\n", hour, result);

	return 0;
}