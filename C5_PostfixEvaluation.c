#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>  // For pow()

#define MAX 100

int stack[MAX];
int top = -1;

// Push value onto stack
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

// Pop value from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}


int main() {
    char postfix[MAX];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    result = eval(postfix);

    printf("Result is: %d\n", result);
    return 0;
}
