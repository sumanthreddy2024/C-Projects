#include <stdio.h>

#define MAX 10

void readMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int choice;
    int rows1, cols1, rows2, cols2;
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];

    while (1) {
        printf("\n--- Matrix Calculator ---\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rows and columns of the matrices: ");
                scanf("%d %d", &rows1, &cols1);
                rows2 = rows1;
                cols2 = cols1;
                printf("Enter elements of first matrix:\n");
                readMatrix(matrix1, rows1, cols1);
                printf("Enter elements of second matrix:\n");
                readMatrix(matrix2, rows2, cols2);
                addMatrices(matrix1, matrix2, result, rows1, cols1);
                printf("Resultant Matrix:\n");
                printMatrix(result, rows1, cols1);
                break;

            case 2:
                printf("Enter rows and columns of the matrices: ");
                scanf("%d %d", &rows1, &cols1);
                rows2 = rows1;
                cols2 = cols1;
                printf("Enter elements of first matrix:\n");
                readMatrix(matrix1, rows1, cols1);
                printf("Enter elements of second matrix:\n");
                readMatrix(matrix2, rows2, cols2);
                subtractMatrices(matrix1, matrix2, result, rows1, cols1);
                printf("Resultant Matrix:\n");
                printMatrix(result, rows1, cols1);
                break;

            case 3:
                printf("Enter rows and columns of first matrix: ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter rows and columns of second matrix: ");
                scanf("%d %d", &rows2, &cols2);
                if (cols1 != rows2) {
                    printf("Matrix multiplication not possible!\n");
                    break;
                }
                printf("Enter elements of first matrix:\n");
                readMatrix(matrix1, rows1, cols1);
                printf("Enter elements of second matrix:\n");
                readMatrix(matrix2, rows2, cols2);
                multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
                printf("Resultant Matrix:\n");
                printMatrix(result, rows1, cols2);
                break;

            case 4:
                printf("Enter rows and columns of the matrix: ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter elements of the matrix:\n");
                readMatrix(matrix1, rows1, cols1);
                transposeMatrix(matrix1, result, rows1, cols1);
                printf("Transpose of the Matrix:\n");
                printMatrix(result, cols1, rows1);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

