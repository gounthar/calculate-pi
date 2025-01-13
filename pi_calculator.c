#include <stdio.h>
#include <stdlib.h>

void calculate_pi(int decimals) {
    int len = (decimals / 4 + 1) * 14; // Calculate array length
    int *arr = (int *)malloc(len * sizeof(int));
    int carry = 0;
    int sum = 0;

    // Initialize the array
    for (int i = 0; i < len; i++) {
        arr[i] = 2000;
    }

    // Calculate pi digits
    for (int i = len; i > 0; i -= 14) {
        sum = 0;
        for (int j = i; j > 0; j--) {
            sum = sum * j + 10000 * arr[j - 1];
            arr[j - 1] = sum % (2 * j - 1);
            sum /= (2 * j - 1);
        }
        printf("%04d", carry + sum / 10000);
        carry = sum % 10000;
    }

    printf("\n");
    free(arr);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_decimals>\n", argv[0]);
        return 1;
    }

    int decimals = atoi(argv[1]);
    if (decimals <= 0) {
        printf("Please provide a positive number of decimals.\n");
        return 1;
    }

    calculate_pi(decimals);
    return 0;
}

