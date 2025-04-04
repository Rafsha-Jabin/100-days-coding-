#include <stdio.h>
#include <string.h>

#define N 200000
char str[N];
int pre[N];
int len[N];

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc --) {
        memset(pre, -1 , sizeof(pre));
        memset(len, 0, sizeof(len));
        scanf("%s", str);
        int n = strlen(str);
        long long sum = 0;
        int k = -1;
        int pos = 0;
        while (pos + 1 < n) {
            if (str[k + 1] == str[pos + 1]) {
                k++; pos++;
                pre[pos] = k;
                len[pos - k] = k + 1;
            } else if (k == -1) {
                pos++;
            } else {
                k = pre[k];
                len[pos - k] = k + 1;
            }
        }
        while (k > 0) {
            k = pre[k];
            len[pos - k] = k + 1;
        }
        len[0] = n;
        for (int i = 0; i < n; i++) {
            sum += len[i];
        }

        for (int i = 0; i < n; i++) {
            if (len[i] == 0) {
                for (int j = 0; i + j < n; j++) {
                    if (str[j] == str[i+j]) {
                        sum++;
                    } else {
                        break;
                    }
                }
            }
        }
        printf("%lld\n", sum);
    }
}
