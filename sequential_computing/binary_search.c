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

int binary_search(int array[], int n, int value){
	int left = 0, right = n - 1;
	
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (array[mid] == value) {
            return mid; // Element found, return its index.
        }
		
		if(array[mid] < value){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return -1;
}

int main(){
	int n;
	printf("Enter the number elements of array: ");
	scanf("%d", &n);
	
	int array[n];
	enter_array(array, n);
	printf("The array just entered is: \n");
	print_array(array, n);
	
	int value;
	printf("Enter the value to find: ");
	scanf("%d", &value);
	int result = binary_search(array, n, value);
	
	if(result == -1){
		printf("The array does not contain the value %d", value);
	}
	else{
		printf("The element with value %d is in position: %d", array[result], result + 1);
	}
	
	return 0;
}
