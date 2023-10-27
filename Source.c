#include <stdio.h>
#define N 20
//#include "./test.txt"

int mSizeInput(int *size) {
	int size_n = 0;
	if (!scanf_s("%d", &size_n) || size_n > 20 || size_n < 1){
		return 0;
	}
	*size = size_n;
	return 1;
}

int matrixCIN(float matrix[][N], int size_n, int size_m) {
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++) {
			if (!scanf_s("%f", &matrix[i][j])) {
				return 0;
			}
		}
	}
	return 1;
}

void matrixCOUT(float matrix[][N], int size_n, int size_m) {
	for (int i = 0; i < size_n; i++) {
		printf("\n");
		for (int j = 0; j < size_m; j++) {
			printf("%5.2f ", matrix[i][j]);
		}
	}
}

float findMin(const float matrix[][N], int size_n, int size_m) {
	float min = matrix[0][0];
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++) {
			float currEl = matrix[i][j];
			if (min > currEl) min = currEl;
		}
	}
	return min;
}

float findMax(const float matrix[][N], int size_n, int size_m) {
	float max = matrix[0][0];
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++) {
			float currEl = matrix[i][j];
			if (max < currEl) max = currEl;
		}
	}
	return max;
}

void composeNewMatrixFromOld(const float matrixOld[][N], float matrixNew[][N], int size_n, int size_m) {
	float diff = 0;
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++) {
			diff = findMax(matrixOld, i + 1, j + 1) - findMin(matrixOld, i + 1, j + 1);
			matrixNew[i][j] = diff;
		}
	}
}

void main() {
	int n = 0;
	float arrayA[N][N], arrayB[N][N];

	printf("Input matrix size\n");
	if (!mSizeInput(&n)) {
		printf("You entered invalid matrix size, input integer greater than 0 less than %d\n", N);
		return;
	}

	printf("Input matrix\n");
	if (!matrixCIN(arrayA, n, n)) {
		printf("You entered not a number\n");
		return;
	}

	composeNewMatrixFromOld(arrayA, arrayB, n, n);

	printf("\nYour matrix\n");
	matrixCOUT(arrayA, n, n);

	printf("\n");

	printf("\nNew matrix\n");
	matrixCOUT(arrayB, n, n);
}

