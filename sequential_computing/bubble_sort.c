#include<stdio.h>			/*standard input/output*/

/*
Test case: 10 1 7 44 3 3 57 93 5 94 72
Result: 1 3 3 5 7 44 57 72 93 94
*/

void enter_array(int array[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
}

void print_array(int array[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void pubble_sort(int array[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	int array[n];
	
	enter_array(array, n);
	printf("The array just entered is: \n");
	print_array(array, n);
	
	pubble_sort(array, n);
	
	printf("The array after sorting is: \n");
	print_array(array, n);
	
	return 0;
}
