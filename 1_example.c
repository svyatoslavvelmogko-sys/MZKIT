#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[20];
    int min, max, sum = 0;
    int minvalue, maxvalue;

    int minrandom, maxrandom;

    printf("Enter minimum random number: ");
    scanf_s("%d", &minrandom);

    printf("Enter maximum random number: ");
    scanf_s("%d", &maxrandom);

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        a[i] = rand() % (maxrandom - minrandom + 1) + minrandom;
        printf("%d ", a[i]);
    }

    min = a[0];
    max = a[0];

    for (int i = 0; i < 20; i++) {
        sum += a[i];

        if (a[i] < min) {
            min = a[i];
        }

        if (a[i] > max) {
            max = a[i];
        }
    }

    float average = (float)sum / 20;

    printf("\nMinimum: %d", min);
    printf("\nMaximum: %d", max);
    printf("\nAverage: %.2f", average);

    return 0;
}