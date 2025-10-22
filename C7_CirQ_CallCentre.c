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

//Enqueue Operation
void addCall(Call c) {
    if (isFull()) {
        printf("Queue Overflow\n");
        printf("Cannot Add another call");
        return;
    }
    if (isEmpty()) {
        front=0;
        rear=0;
    }else {
        rear = (rear + 1) % MAX;
    }

    queueArr[rear] = c;
    printf("Added Call: Call ID %d Caller Name %s",c.callID,c.callerName);
}

void deleteCal() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    Call c = queueArr[front];
    printf("Deleting Call Call ID %d Caller Name %s",c.callID,c.callerName);
    if (front == rear) {
        front=rear=-1;
    }else {
        front = (front + 1) % MAX;
    }
}