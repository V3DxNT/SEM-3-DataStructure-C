#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>  // For pow()

#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    char postfix[MAX];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    result = eval(postfix);

    printf("Result is: %d\n", result);
    return 0;
}
