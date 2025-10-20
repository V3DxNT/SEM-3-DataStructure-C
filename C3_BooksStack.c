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
