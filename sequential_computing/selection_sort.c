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

void selection_sort(int array[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++){
		int min = i;
		for(j = i + 1; j < n; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int main(){
	int n;
	printf("Enter the number elements in the array: ");
	scanf("%d", &n);
	
	int array[n];
	enter_array(array, n);
	printf("The array just entered is: \n");
	print_array(array, n);
	
	selection_sort(array, n);
	
	printf("The array after sorting is: \n");
	print_array(array, n);
		
	return 0;
}
