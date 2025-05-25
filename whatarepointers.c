#include <stdio.h>
void main() {
    int x = 10;
    int* y = &x;
    *y = 6;
    printf("%d", x);
    printf("\n");
}