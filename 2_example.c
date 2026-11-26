#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[20][20];
    int n, min, minRow;
    int minrandom, maxrandom;
    int temp;

    printf("Enter matrix size: ");
    scanf_s("%d", &n);

    printf("Enter minimum random number: ");
    scanf_s("%d", &minrandom);

    printf("Enter maximum random number: ");
    scanf_s("%d", &maxrandom);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (maxrandom - minrandom + 1) + minrandom;
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    min = a[0][0];
    minRow = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
                minRow = i;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        temp = a[0][j];
        a[0][j] = a[minRow][j];
        a[minRow][j] = temp;
    }

    printf("\nNew matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}