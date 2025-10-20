#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

//Stack Implementation
char STACK[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack OverFlow :is full\n");
        return;
    }
    STACK[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack UnderFlow : is empty\n");
        return -1;
    }
    return STACK[top--];
}

char peek() {
    if (top == -1) {
        printf("Stack UnderFlow : is empty\n");
        return -1;
    }
    return STACK[top];
}

//Function to return precedence of operator
int precedence(char op) {
    switch(op) {
        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}