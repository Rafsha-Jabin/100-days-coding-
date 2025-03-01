#include <stdio.h>
#include <limits.h>

void miniMaxSum(int arr[]) {
    long long total_sum = 0;
    int min_val = INT_MAX, max_val = INT_MIN;

    for (int i = 0; i < 5; i++) {
        total_sum += arr[i];
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    long long min_sum = total_sum - max_val;
    long long max_sum = total_sum - min_val;

    printf("%lld %lld\n", min_sum, max_sum);
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    miniMaxSum(arr);
    return 0;
}
