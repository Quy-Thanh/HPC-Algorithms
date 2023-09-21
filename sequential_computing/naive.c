#include<stdio.h>

/*
test case:
3 3 3
1 2 3
4 5 6
7 8 9
1 2 3
4 5 6
7 8 9

result:
30 36 42
66 81 96
102 126 150

*/

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
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

void Naive(int n, int k, int m, int A[n][k], int B[k][m], int C[n][m]) {
    int i, j, o;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            C[i][j] = 0;
            for (o = 0; o < k; o++) {
                C[i][j] += A[i][o] * B[o][j];
            }
        }
    }
}

int main() {
	int n, k, m;
    
    printf("Number of rows of matrix A: ");
    scanf("%d", &n);
    printf("Number of columns of matrix A (rows of matrix B): ");
    scanf("%d", &k);
    printf("Number of columns of matrix B: ");
    scanf("%d", &m);
    
    int A[n][k];
    int B[k][m];
    int C[n][m];
    
    printf("Enter value of matrix A: \n");
    enter_matrix(A, n, k);
    printf("Enter value of matrix B: \n");
	enter_matrix(B, k, m);
	
	Naive(n, k, m, A, B, C);
	
	printf("\n*******----*******\n\nMatrix C = A x B:\n");
	print_matrix(C, n, m);
	return 0;
}

