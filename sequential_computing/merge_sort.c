#include<stdio.h>

void enter_array(int array[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Element %d: ", i + 1);
		scanf("%d", &array[i]);
	}
}

void print_array(int array[], int n) {
	int i;
	for(i = 0; i < n; i++){
		printf("%d    ", array[i]);
	}
	printf("\n");
}

void merge(int array[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
	int i, j, k;
	for (i = 0; i < n1; i++) {
		L[i] = array[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = array[m + j + 1];
	}
	j = 0;
	i = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int array[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		
		merge_sort(array, l, m);
		merge_sort(array, m + 1, r);
		
		merge(array, l, m, r);
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
	
	merge_sort(array, 0, n - 1);
	
	printf("The array after sorting is: \n");
	print_array(array, n);
	return 0;
}
