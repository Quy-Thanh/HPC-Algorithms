#include <stdio.h>
#define MAX 100

/*
test case:
4 4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

result:
-270  -294  110  120
-70  -78  254  280
314  356  398  440
426  484  542  600

*/

void EnterMat(int array[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Element [%d][%d]:", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
}

void PrintMat(int array[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }
}

void AddMat(int rows, int cols, int mat1[][100], int mat2[][100], int result[][100]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void SubMat(int rows, int cols, int mat1[][100], int mat2[][100], int result[][100]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void MulMat2x2(int mat1[][100], int mat2[][100], int result[][100]) {
    int M1 = (mat1[0][0] + mat1[1][1]) * (mat2[0][0] + mat2[1][1]);
    int M2 = (mat1[1][0] + mat1[1][1]) * mat2[0][0];
    int M3 = mat1[0][0] * (mat2[0][1] - mat2[1][1]);
    int M4 = mat1[1][1] * (mat2[1][0] - mat2[0][0]);
    int M5 = (mat1[0][0] + mat1[0][1]) * mat2[1][1];
    int M6 = (mat1[1][0] - mat1[0][0]) * (mat2[0][0] + mat2[0][1]);
    int M7 = (mat1[0][1] - mat1[1][1]) * (mat2[1][0] + mat2[1][1]);

    result[0][0] = M1 + M4 - M5 + M7;
    result[0][1] = M3 + M5;
    result[1][0] = M2 + M4;
    result[1][1] = M1 - M2 + M3 + M6;
}

void Strassen(int mat1[][100], int mat2[][100], int result[][100], int rows, int cols) {
    if (rows == 2 && cols == 2) {
        MulMat2x2(mat1, mat2, result);
        return;
    }

    int rows_1 = rows / 2;
    int cols_1 = cols / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];

    int temp_1[MAX][MAX], temp_2[MAX][MAX];

    int i, j;
    for (i = 0; i < rows_1; i++) {
        for (j = 0; j < cols_1; j++) {
            A11[i][j] = mat1[i][j];
            A12[i][j] = mat1[i][j + cols_1];
            A21[i][j] = mat1[i + rows_1][j];
            A22[i][j] = mat1[i + rows_1][j + cols_1];

            B11[i][j] = mat2[i][j];
            B12[i][j] = mat2[i][j + cols_1];
            B21[i][j] = mat2[i + rows_1][j];
            B22[i][j] = mat2[i + rows_1][j + cols_1];
        }
    }

    // Recalculate matrix M1
    AddMat(rows_1, cols_1, A11, A22, temp_1);
    AddMat(rows_1, cols_1, B11, B22, temp_2);
    Strassen(temp_1, temp_2, M1, rows_1, cols_1);

    // Recalculate matrix M2
    AddMat(rows_1, cols_1, A21, A22, temp_1);
    Strassen(temp_1, B11, M2, rows_1, cols_1);

    // Recalculate matrix M3
    SubMat(rows_1, cols_1, B12, B22, temp_2);
    Strassen(A11, temp_2, M3, rows_1, cols_1);

    // Recalculate matrix M4
    SubMat(rows_1, cols_1, B21, B11, temp_2);
    Strassen(A22, temp_2, M4, rows_1, cols_1);

    // Recalculate matrix M5
    AddMat(rows_1, cols_1, A11, A12, temp_1);
    Strassen(temp_1, B22, M5, rows_1, cols_1);

    // Recalculate matrix M6
    SubMat(rows_1, cols_1, B21, B11, temp_1);
    AddMat(rows_1, cols_1, A11, A12, temp_2);
    Strassen(temp_1, temp_2, M6, rows_1, cols_1);

    // Recalculate matrix M7
    SubMat(rows_1, cols_1, B12, B22, temp_1);
    AddMat(rows_1, cols_1, A21, A22, temp_2);
    Strassen(temp_1, temp_2, M7, rows_1, cols_1);

    // Recalculate matrix C11
    AddMat(rows_1, cols_1, M1, M4, temp_1);
    SubMat(rows_1, cols_1, temp_1, M5, temp_2);
    AddMat(rows_1, cols_1, temp_2, M7, C11);

    // Recalculate matrix C12
    AddMat(rows_1, cols_1, M3, M5, C12);

    // Recalculate matrix C21
    AddMat(rows_1, cols_1, M2, M4, C21);

    // Recalculate matrix C22
    SubMat(rows_1, cols_1, M1, M2, temp_1);
    AddMat(rows_1, cols_1, temp_1, M3, temp_2);
    AddMat(rows_1, cols_1, temp_2, M6, C22);

    for (i = 0; i < rows_1; i++) {
        for (j = 0; j < cols_1; j++) {
            result[i][j] = C11[i][j];
            result[i][j + cols_1] = C12[i][j];
            result[i + rows_1][j] = C21[i][j];
            result[i + rows_1][j + cols_1] = C22[i][j];
        }
    }
}

int main() {
    int n, k, m;

    printf("Number of rows of matrix A: ");
    scanf("%d", &n);
    printf("Number of columns of matrix A (rows of B): ");
    scanf("%d", &k);
    printf("Number of columns of matrix B: ");
    scanf("%d", &m);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter matrix A:\n");
    EnterMat(A, n, k);
    printf("Enter matrix B:\n");
    EnterMat(B, k, m);

    Strassen(A, B, C, n, m);

    printf("\nC = A x B = \n");
    PrintMat(C, n, m);
    
    return 0;
}

