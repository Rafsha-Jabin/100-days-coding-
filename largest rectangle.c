#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}

long largestRectangle(int h_count, int* h) {
    long max_area = 0;
    for (int i = 0; i < h_count; i++) {
        for (int j = i; j < h_count; j++) {
            int current_min = h[i];
            for (int k = i; k <= j; k++) {
                current_min = min(current_min, h[k]);
            }
            long current_area = (long)current_min * (j - i + 1);
            if (current_area > max_area) {
                max_area = current_area;
            }
        }
    }
    return max_area;
}

int main() {
    int n;
    scanf("%d", &n);
    int* h = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    long result = largestRectangle(n, h);
    printf("%ld\n", result);
    free(h);
    return 0;
}
