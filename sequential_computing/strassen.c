#include <stdio.h>
#define max 100

void enter_matrix(int array[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Element [%d][%d]:", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
}

void print_matrix(int array[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }
}

void Strassen() {
	//
}


int main() {
    int ar, ac, br, bc;
    
    int A[ar][ac];
    int B[br][bc];
    int C[ar][bc];
    
    printf("Number of rows of matrix A: ");
    scanf("%d", &ar);
    printf("Number of columns of matrix A: ");
    scanf("%d", &ac);
    enter_matrix(A, ar, ac);
    
    printf("Number of rows of matrix B: ");
    scanf("%d", &br);
    printf("Number of columns of matrix B: ");
    scanf("%d", &bc);
	enter_matrix(B, br, bc);
	
	Strassen(A, B, C);
	
	printf("\n*******----*******\n\nC = A x B = \n");
	print_matrix(C, ar, bc);
    return 0;
}

