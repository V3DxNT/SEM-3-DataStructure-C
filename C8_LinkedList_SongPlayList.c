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

void addSong() {
    char name[100];
    printf("Enter the Song Name\n");
    scanf("%s",name);

    Node* newNode = createNode(name);
    if (head==NULL) {
        head = newNode;
    }else {
        Node* temp = head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Added:%s Successfully\n",name);
    return;
}

void playStart() {
    if (head==NULL) {
        printf("No Song in the List\n");
        return;
    }
    Node* temp = head;
    printf("Playing Songs:\n");
    while (temp->next!=NULL) {
        printf("%s\n",temp->song);
        temp = temp->next;
    }
    free(temp);
    return;
}


