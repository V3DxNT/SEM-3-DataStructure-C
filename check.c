#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,rev,digit;
    printf("Enter a nUmber");
    scanf("%d", &n);
    int original=n;
    while (n>0) {
        digit = n%10;
        rev = rev*10 + digit;
        n = n/10;
    }
    printf("The reverse of %d is %d", original, rev);
    return 0;
}