#include <stdio.h>
#include <stdlib.h>

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
                displayArray();
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

    }
}
