#include <stdio.h>
#define max 100

void enter_matrix(int array[max][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Element [%d][%d]:", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
}

void print_matrix(int array[max][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int array[n][m];
    enter_matrix(array, n, m);
    printf("The array just entered is: \n");
    print_matrix(array, n, m);

    return 0;
}

