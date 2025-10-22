#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Node {
    char song[100];
    struct Node* next;
}Node;

Node* head=NULL;

Node* createNode(char* name) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strcpy(newNode->song,name);
    newNode->next=NULL;
    return newNode;
}

