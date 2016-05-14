#include <stdio.h>
int count = 1;
void move(int diskNum, char a, char b) {
    printf("%d.Move the %d disk from %c to %c\n", count++, diskNum, a, b);
}
void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        move(n, x, z);
    } else {
        hanoi(n - 1, x, z, y);
        move(n, x, z);
        hanoi(n - 1, y, x, z);
    }
}

int main() {
    int n;
    printf("Please input n:", &n);
    scanf("%d", &n);
    hanoi(n, 'X', 'Y', 'Z');
    return 0;
}