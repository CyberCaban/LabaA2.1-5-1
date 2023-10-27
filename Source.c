#include <stdio.h>
#define N 20


void findMinMax(const float matrix[][N], int size_n, int size_m, float* max, float* min) {
	*min = *max = matrix[0][0];
	for (int i = 0; i < size_n; i++){
		for (int j = 0; j < size_m; j++) {
			float currEl = matrix[i][j];
			if (*min > currEl) *min = currEl;
			if (*max < currEl) *max = currEl;
		}
	}
}

float myFloatInput() {
	int t;
	float res;

	t = scanf_s("%f", &res);

	while (!t) {
		printf("You entered not a number\n");
		scanf_s("%*c");
		t = scanf_s("%f", &res);
	}

	return res;
}

void matrixCOUT(float matrix[][N], int size_n, int size_m) {
	for (int i = 0; i < size_n; i++) {
		printf("\n");
		for (int j = 0; j < size_m; j++) {
			printf("%5.2f ", matrix[i][j]);
		}
	}
}

void main() {
	int n = 0;
	float maxA, minA, t, arrayA[N][N], arrayB[N][N];

	printf("Input matrix size\n");
	t = scanf_s("%d", &n);

	if (!t || n > 20 || n < 1) {
		printf("You entered invalid matrix size, input integer greater than 0 less than %d\n", N);
		return;
	}

	printf("Input matrix\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrayA[i][j] = myFloatInput();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			findMinMax(arrayA, i + 1, j + 1, &maxA, &minA);
			arrayB[i][j] = maxA - minA;
		}
	}

	printf("\nYour matrix\n");
	matrixCOUT(arrayA, n, n);

	printf("\n");

	printf("\nNew matrix\n");
	matrixCOUT(arrayB, n, n);
}

