#include <stdio.h>
#define MAX 10

void readMatrix(int a[MAX][MAX], int rows, int cols, const char *name) {
    int i, j;
    printf("Enter elements for %s (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s[%d][%d] = ", name, i + 1, j + 1);
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Invalid input.\n");
                return;
            }
        }
    }
}

void printMatrix(int a[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) printf("%5d", a[i][j]);
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                 int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                      int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transposeMatrix(int a[MAX][MAX], int result[MAX][MAX],
                     int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[j][i] = a[i][j];
}

int main(void) {
    int choice, r1, c1, r2, c2;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];

    do {
        printf("\n=== Matrix Operations ===\n");
        printf("1. Matrix Addition\n2. Matrix Multiplication\n");
        printf("3. Transpose of a Matrix\n0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter rows and columns (1-%d): ", MAX);
                scanf("%d %d", &r1, &c1);
                if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
                    printf("Dimensions must be between 1 and %d.\n", MAX);
                    break;
                }
                readMatrix(a, r1, c1, "A");
                readMatrix(b, r1, c1, "B");
                addMatrices(a, b, result, r1, c1);
                printf("A + B =\n");
                printMatrix(result, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns of B: ");
                scanf("%d %d", &r2, &c2);
                if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX ||
                    r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
                    printf("Dimensions must be between 1 and %d.\n", MAX);
                    break;
                }
                if (c1 != r2) {
                    printf("Multiplication not possible: columns of A must equal rows of B.\n");
                    break;
                }
                readMatrix(a, r1, c1, "A");
                readMatrix(b, r2, c2, "B");
                multiplyMatrices(a, b, result, r1, c1, c2);
                printf("A x B =\n");
                printMatrix(result, r1, c2);
                break;

            case 3:
                printf("Enter rows and columns (1-%d): ", MAX);
                scanf("%d %d", &r1, &c1);
                if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
                    printf("Dimensions must be between 1 and %d.\n", MAX);
                    break;
                }
                readMatrix(a, r1, c1, "A");
                transposeMatrix(a, result, r1, c1);
                printf("Transpose of A =\n");
                printMatrix(result, c1, r1);
                break;

            case 0:
                printf("Exiting Matrix Operations.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}