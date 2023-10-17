#include <stdio.h>
#define N 20

void main() {
	int n = 0, m = 0, maxA, minA, t, arrayA[N][N], arrayB[N][N], rows = 6, col = 3, diff;

	printf("Input matrix size\n");
	t = scanf_s("%d", &n);

	if (!t || n > 20 || n < 1) {
		printf("You entered invalid matrix size, input integer greater than 0 less than %d\n", N);
		return;
	}

	printf("Input matrix\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (scanf_s("%d", &t)) {
				arrayA[i][j] = t;
			}
			else {
				printf("You entered not a number\n");
				return;
			}
		}
	}

	if (rows > n) {
		rows = n;
	}
	if (col > n){
		col = n;
	}
	
	maxA = minA = arrayA[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			if (maxA < arrayA[i][j]) {
				maxA = arrayA[i][j];
			}
			if (minA > arrayA[i][j]) {
				minA = arrayA[i][j];
			}
		}
	}

	diff = maxA - minA;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			arrayB[i][j] = diff;
		}
	}

	printf("\nYour matrix\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", arrayA[i][j]);
		}
	}
	printf("\nNew matrix\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", arrayB[i][j]);
		}
	}
}