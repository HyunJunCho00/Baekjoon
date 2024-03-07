#include <stdio.h>
#include <math.h>

#define line 1e-10

double check(double x, int A, int B, int C) {
    return A * x + B * sin(x) - C;
}

double funct(int A, int B, int C, double low, double high) {
    double mmid, mid;
    while (high - low > line) {
        mid = (high + low) / 2;
        mmid = check(mid, A, B, C);
        if (mmid == 0.0)
            return mid;
        else if (mmid * check(low, A, B, C) < 0)
            high = mid;
        else
            low = mid;
    }
    return (low + high) / 2;
}

int main(void) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    double result = funct(A, B, C, -10000000,100000000);
    printf("%.10lf\n", result);
    return 0;
}