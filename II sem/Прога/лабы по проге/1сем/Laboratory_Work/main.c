#include <stdio.h>

int main() {
    printf("Enter the number: ");
    int n, sum_div = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum_div += i;
        }
    }
    if (n > sum_div) {
        printf("The number is insufficient\n");
    } else {
        printf("The number is not insufficient\n");
    }
    return 0;
}
