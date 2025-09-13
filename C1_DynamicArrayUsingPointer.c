#include <stdio.h>
#include <stdlib.h>

void menu();
int* createArray(int);
void displayArray(int*, int);
int* insertElem(int*, int, int,int);
int* deleteElem(int*, int, int);
void searchElem(int*, int, int);

int main() {
    int *arr=NULL;
    int n=0,choice,elem,pos;

    printf("Dynamic Array Operations Using Pointers ");

    while(1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d",&n);
                arr=createArray(n);
                break;

            case 2:
                if (arr==NULL) printf("Array is Not yet Created");
                displayArray(arr,n);
                break;

            case 3:

                printf("Enter the element to insert: ");
                scanf("%d",&elem);

                printf("Enter the position to insert: ");
                scanf("%d",&pos);

                arr=insertElem(arr,&n,elem,pos);
                break;

            case 4:
                printf("Enter the position to delete (0 to %d): ",n-1);
                scanf("%d",&pos);

                arr=deleteElem(arr,&n,pos);
                break;

            case 5:
                printf("Enter the element to search: ");
                scanf("%d",&elem);
                searchElem(arr,n,elem);
                break;
            case 6:
                printf("Exiting...\n");
                free(arr);
                exit(0);

            default:
                printf("Invalid Choice");
        }
    }
}


void menu() {
    printf("---------MENU-----------\n");
    printf("1. Create Array\n");
    printf("2. Display Array\n");
    printf("3. Insert Element\n");
    printf("4. Delete Element\n");
    printf("5. Search Element\n");
    printf("6. Exit\n");
    printf("--------------------\n");
}

int* createArray(int n) {
    int *arr=(int*)malloc(sizeof(int)*n);
    if (arr==NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }
    printf("Enter %d elements:\n ",n);
    for(int i=0;i<n;i++) {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    return arr;
}

