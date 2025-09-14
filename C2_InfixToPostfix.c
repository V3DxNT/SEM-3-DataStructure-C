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

