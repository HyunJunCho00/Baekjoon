#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dp[50001];

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int n1 = (int)sqrt((double)n);
    for (int i = 1; i <= n; i++) {
        dp[i] = i; 
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n1; j++) {
            if (j * j <= i)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            else
                break;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
