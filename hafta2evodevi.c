#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS_A 2
#define COLS_A 3

#define ROWS_B 3
#define COLS_B 2

int matrixA[ROWS_A][COLS_A];
int matrixB[ROWS_B][COLS_B];

void randomvaluegenerator(int rows, int cols, int matrix[rows][cols]);

void printMatrix(int rows, int cols, int matrix[rows][cols]);

void sumMatrix(int matrixA[ROWS_A][COLS_A], int matrixB[ROWS_B][COLS_B]);

void multiMatrix(int matrixA[ROWS_A][COLS_A], int matrixB[ROWS_B][COLS_B]);

int main() {
    srand(time(NULL));
    randomvaluegenerator(ROWS_A, COLS_A, matrixA);
    randomvaluegenerator(ROWS_B, COLS_B, matrixB);

    printf("****1.matrix****\n");
    printMatrix(ROWS_A, COLS_A, matrixA);
    printf("**** 2. Matrix ****\n");
    printMatrix(ROWS_B, COLS_B, matrixB);

    printf("**** Sum Matrix ****\n");
    if (ROWS_A != ROWS_B) {
        printf("Addition is undefined.\n");
    } else {
        sumMatrix(matrixA, matrixB);
    }

    printf("**** Multi Matrix ****\n");
    if (COLS_A != ROWS_B) {
        printf("Multiplication is undefined.\n");
    } else {
        multiMatrix(matrixA, matrixB);
    }

    return 0;
}

void randomvaluegenerator(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sumMatrix(int matrixA[ROWS_A][COLS_A], int matrixB[ROWS_B][COLS_B]) {
    int resultMatrix[ROWS_A][ROWS_B];

    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < ROWS_A; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    printMatrix(ROWS_A, COLS_A, resultMatrix);
}

void multiMatrix(int matrixA[ROWS_A][COLS_A], int matrixB[ROWS_B][COLS_B]) {
    int resultMatrix[ROWS_A][COLS_B];

    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < ROWS_A; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < COLS_A; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printMatrix(ROWS_A, COLS_B, resultMatrix);
}