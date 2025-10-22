#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct Call {
    int callID;
    char callerName[50];
}Call;

Call queueArr[MAX];
int front, rear=-1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}
