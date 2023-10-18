#include <stdio.h>
#define N 20

void main() {
	int n = 0, m = 0, maxA, minA, t, arrayA[N][N], arrayB[N][N], diff;

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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxA = arrayA[0][0];
			for (int o = 0; o < i + 1; o++) {
				for (int p = 0; p < j + 1; p++) {
					if (maxA < arrayA[o][p]) maxA = arrayA[o][p];
				}
			}

			minA = arrayA[0][0];
			for (int o = 0; o < i + 1; o++) {
				for (int p = 0; p < j + 1; p++) {
					if (minA > arrayA[o][p]) minA = arrayA[o][p];
				}
			}

			arrayB[i][j] = maxA - minA;
		}
	}


	printf("\nYour matrix\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", arrayA[i][j]);
		}
	}
	printf("\n");

	printf("\nNew matrix\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", arrayB[i][j]);
		}
	}
}

