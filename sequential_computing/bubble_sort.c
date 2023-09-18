#include<stdio.h>			/*standard input/output*/

void enter_array(int array[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d: ", i+1);
		scanf("%d", &array[i]);
	}
}

void print_array(int array[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d    ", array[i]);
	}
	printf("\n");
}

void pubble_sort(int array[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
	{
		for(j = n - 1; j > i; j--)
		{
			if(array[j] < array[j - 1])
			{
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

int main(){
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	int array[n];
	
	enter_array(array, n);
	print_array(array, n);
	
	pubble_sort(array, n);
	
	printf("Mang sau khi da sap xep la: \n");
	print_array(array, n);
	
	return 0;
}
