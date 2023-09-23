#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Hàm tính tích c?a hai ma tr?n
void matrix_multiply(int** A, int** B, int** result, int rowsA, int colsA, int colsB) {
    #pragma omp parallel for
    int i, j, k;
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rowsA = 3;
    int colsA = 3;
    int rowsB = 3;
    int colsB = 3;

    // Kh?i t?o và ?i?n giá tr? cho hai ma tr?n A và B
    int** A = (int**)malloc(rowsA * sizeof(int*));
    int** B = (int**)malloc(rowsB * sizeof(int*));
    int** result = (int**)malloc(rowsA * sizeof(int*));
    
	int i, j;
    for (i = 0; i < rowsA; i++) {
        A[i] = (int*)malloc(colsA * sizeof(int));
        B[i] = (int*)malloc(colsB * sizeof(int));
        result[i] = (int*)malloc(colsB * sizeof(int));
    }

    // Kh?i t?o giá tr? m?ng A và B (? ?ây ta s? d?ng giá tr? ng?u nhiên)
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            A[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            B[i][j] = rand() % 10;
        }
    }

    // Tính tích hai ma tr?n b?ng l?p trình song song
    matrix_multiply(A, B, result, rowsA, colsA, colsB);

    // In ma tr?n k?t qu?
    printf("Matrix A:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nResultant Matrix:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Gi?i phóng b? nh?
    for (i = 0; i < rowsA; i++) {
        free(A[i]);
        free(B[i]);
        free(result[i]);
    }
    free(A);
    free(B);
    free(result);

    return 0;
}

