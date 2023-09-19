#include<stdio.h>

void enter_array(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("Element %d: ", i + 1);
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

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int array[], int low, int high){
	int left = low, right = high - 1;
	int pivot = array[high];
	while(1){
		while(left <= right && array[left] < pivot) left++;
		while(right >= left && array[right] > pivot) right--;
		if(left >= right) break;
		swap(&array[left], &array[right]);
		left++;
		right--;
	}
	swap(&array[left], &array[high]);
	return left;
}

void quick_sort(int array[], int low, int high){
	if(low < high){
	int index = partition(array, low, high);
	
	quick_sort(array, low, index - 1);
	quick_sort(array, index + 1, high);
	}
}

int main(){
	int n;
	printf("Enter number elements of the array: ");
	scanf("%d", &n);
	
	int array[n];
	enter_array(array, n);
	printf("The array just entered is: \n");
	print_array(array, n);
	
	quick_sort(array, 0, n - 1);
	
	printf("The array after sorting is: \n");
	print_array(array, n);
	return 0;
}
