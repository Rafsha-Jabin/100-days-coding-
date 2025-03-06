#include <stdio.h>

void plusMinus(int arr[], int n) {
    int positive_count = 0, negative_count = 0, zero_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positive_count++;
        } else if (arr[i] < 0) {
            negative_count++;
        } else {
            zero_count++;
        }
    }

    printf("%.6f\n", (float)positive_count / n);
    printf("%.6f\n", (float)negative_count / n);
    printf("%.6f\n", (float)zero_count / n);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    plusMinus(arr, n);
    return 0;
}
