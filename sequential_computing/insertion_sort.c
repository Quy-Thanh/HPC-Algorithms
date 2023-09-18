#include<stdio.h>

void enter_array(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
}

void print_array(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d    ", array[i]);
	}
	printf("\n");
}

void insertion_sort(int array[], int n){
	int i, j;
	for(i = 1; i < n; i++){
		j = i;
		int temp = array[i];
		while(j > 0 && temp < array[j - 1]){
			array[j] = array[j - 1];
			j--;
		}
		array[j] = temp;
	}
}

int main(){
	int n;
	printf("Enter the number elements of array: ");
	scanf("%d", &n);
	
	int array[n];
	enter_array(array, n);
	printf("The array just entered is: \n");
	print_array(array, n);
	
	insertion_sort(array, n);
	
	printf("The array after sorting is: \n");
	print_array(array, n);
	
	return 0;
}
