#include<stdio.h>

int CountDigits(int number) {
	int digits = 1;
	while(number >= 10) {
		number /= 10;
		digits += 1;
	}
	return digits;
}

int Max(int num1, int num2) {
	int max = num1 > num2 ? num1 : num2;
	return max
}

int ResultDigits(int a, int b) {
	int max = a >= b ? a : b;
	return max;
}

void ConvertToArray(int array[], int number) {
	int i;
	for (i = CountDigits(number) - 1; i >= 0; i--) {
		array[i] = number % 10;
		number /= 10;
	}
}

void SplitMid(int Result[100], int A[100], int B[100], int m) {
	m = m / 2;
	int i;
	for (i = 0; i < m; i++) {
		A[i] = Result[i];
		B[i] = Result[m + i];
	}
}

void PrintMat(int array[100], int m) {
    int i;
    for (i = 0; i < m; i++) {
    	printf("%d", array[i]);
    }
}

void Mul4Digit(int arrA[100], int arrB[100], int result[100], int n) {
	result[] = Max(CountDigits(arrA), CountDigits(arrB));
}
void sumM(int arrA[100], int arrB[100], int result[100], int n) {
	int i;
	for (i = 0; i < n; i++) {
		result[i] = arrA[i] + arrB[i];
	}
}

void Kratsuba(int arrA[100], int arrB[100], int result[100], int m) {
	int m_new = m / 2;
	while (1) {
		if (m == 1) {
			Mul1Digit(arrA, arrB, result);
			break;
	}
	int A1[m_new], A0[m_new];
	int B1[m_new], B0[m_new];
	Split(arrA, A1, A0, m_new);
	Split(arrB, B1, B0, m_new);
	int P1[100], P2[100], P3[100],  temp_1[100], temp_2[100];
	Kratsuba(A1, B1, P1, m_new);
	Kratsuba(A0, B0, P2, m_new);
	sumM(A1, A0, temp_1, m_new);
	sumM(B1, B0, temp_2, m_new);
	Kratsuba(temp_1, temp_2, P3, m_new);
	}
}

int main() {
	int A, B;
	printf("Enter the number of A B: \n");
	scanf("%d%d", &A,&B);
	
	int m = CountDigits(A);
	int n = CountDigits(B);
	int arrA[m];
	int arrB[m];
	int result[m];
	
	ConvertToArray(arrA, A);
	ConvertToArray(arrB, B);
	
	Split(arrA, arrB, result, m);
	printf("Result: ");
	PrintMat(result, m/2);
	
	return 0;
}
