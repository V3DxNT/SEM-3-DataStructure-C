#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // Maximum size of stack

// Define Book structure
typedef struct {
    char ISBN[20];
    char Title[50];
    char Author[50];
    float Price;
} BOOK;

// Stack
BOOK stack[MAX];
int top = -1;

// Function prototypes
void push();
void pop();
void display();

int main() {
    int choice;

    printf("Book Stack Implementation (Max Size = %d)\n", MAX);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. PUSH (Add Book)\n");
        printf("2. POP (Remove Book)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }
        getchar(); // clear newline left by scanf

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    }
    return 0;
}

// PUSH operation
void push() {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot add more books.\n");
        return;
    }

    BOOK b;

    printf("Enter ISBN: ");
    fgets(b.ISBN, sizeof(b.ISBN), stdin);
    b.ISBN[strcspn(b.ISBN, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Title: ");
    fgets(b.Title, sizeof(b.Title), stdin);
    b.Title[strcspn(b.Title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(b.Author, sizeof(b.Author), stdin);
    b.Author[strcspn(b.Author, "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &b.Price);
    getchar();  // Clear newline left in input buffer

    stack[++top] = b;  // Push book onto stack
    printf("\nBook pushed successfully.\n");
}

// POP operation
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No books to remove.\n");
        return;
    }

    BOOK b = stack[top--];  // Pop the top book from the stack

    printf("\nPopped Book Details:\n");
    printf("ISBN: %s | Title: %s | Author: %s | Price: %.2f\n",
           b.ISBN, b.Title, b.Author, b.Price);
}

