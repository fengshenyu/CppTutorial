#include <stdio.h>
int layer = 0;
int factorial(int n) {
    for (int i = 0; i < layer; i++) {
        printf("  ");
    }
    layer++;
    if (n == 0) {
        return 1;
    } else {
        printf("%d * factorial(%d)\n", n, n - 1);
        return n * factorial(n - 1);
    }
}
int main() {
    int n;
    printf("Input n:");
    scanf("%d", &n);
    printf("Result=%d\n", factorial(n));
    return 0;
}