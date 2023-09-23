#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Hàm merge dùng ?? k?t h?p hai m?ng con ?ã s?p x?p thành m?t m?ng con ?ã s?p x?p
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Hàm mergeSort th?c hi?n s?p x?p m?ng b?ng thu?t toán merge sort v?i l?p trình song song
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    // S? d?ng OpenMP ?? song song hóa vi?c chia m?ng
    #pragma omp parallel sections
    {
        #pragma omp section
        int i;
        for (i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        
        #pragma omp section
        for (i = mid; i < size; i++) {
            right[i - mid] = arr[i];
        }
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // S? d?ng OpenMP ?? song song hóa vi?c tr?n m?ng
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                merge(arr, left, mid, right, size - mid);
            }
        }
    }

    free(left);
    free(right);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // S? d?ng OpenMP ?? song song hóa quá trình s?p x?p
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            mergeSort(arr, size);
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

