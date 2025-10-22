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

    // scanf(" %[^\n]", name);   //For inputs even after a space

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
    while (temp!=NULL) {
        printf("%s\n",temp->song);
        temp = temp->next;
    }
    free(temp);
    return;
}

void playEndRec(Node* node) {
    if (!node) return;
    playEndRec(node->next);
    printf("%s\n",node->song);
}

void playEnd() {
    if (head == NULL) {
        printf("No Song in the List\n");
        return;
    }
    printf("Playing Songs in Reverse Order\n");
    playEndRec(head);
}

void delStart() {
    if (!head) {
        printf("No Song in the List\n");
        return;
    }
    Node* temp = head;
    head=head->next;
    printf("Deleted Song:%s\n",temp->song);
    free(temp);
}

void delEnd() {
    if (head==NULL) {
        printf("No Song in the List\n");
        return;
    }
    if (head->next==NULL) {
        printf("Deleted %s\n",head->song);
        free(head);
        head=NULL;
        return;
    }
    Node* temp = head;
    while (temp->next!=NULL && temp->next->next!=NULL) {
        temp = temp->next;
    }
    printf("Deleted %s\n",temp->next->song);
    temp->next=NULL;
    free(temp);
    return;
}

void menu() {
    printf("-----Song PlayList-------\n");
    printf("1.Add Song\n");
    printf("2.Play From Start\n");
    printf("3.Play From End\n");
    printf("4. Delete From Start\n");
    printf("5. Delete From End\n");
    printf("6. Exit\n");
}


int main() {
    int choice;
    while (1) {
        menu();
        printf("Enter your choice");
        scanf("%d",&choice);
        switch (choice) {
            case 1:addSong(); break;
                case 2:playStart(); break;
                case 3:playEnd(); break;
                case 4:delStart(); break;
                case 5:delEnd(); break;
                case 6:exit(0);
                default:printf("Wrong choice\n");
        }
        printf("\n");
    }
    return 0;
}


















