#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[20][20];
    int n;
    int minRandom, maxRandom;
    int sum = 0, count = 0;

    printf("Enter matrix size: ");
    scanf_s("%d", &n);

    printf("Enter minimum random number: ");
    scanf_s("%d", &minRandom);

    printf("Enter maximum random number: ");
    scanf_s("%d", &maxRandom);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (maxRandom - minRandom + 1) + minRandom;
        }
    }

    printf("\nMatrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nSelected elements:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i < n / 2 && i + j > n - 1) ||
                (i >= n / 2 && i + j < n - 1)) {

                printf("%4d", a[i][j]);
                sum += a[i][j];
                count++;
            }
            else {
                printf("   .");
            }
        }
        printf("\n");
    }

    if (count > 0) {
        printf("\nNumber of elements: %d", count);
        printf("\nAverage: %.2f", (float)sum / count);
    }

    return 0;
}