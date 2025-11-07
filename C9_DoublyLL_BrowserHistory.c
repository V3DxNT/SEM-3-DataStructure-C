#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev, *next;
} Node;

Node *cur = NULL;

Node* createNode(const char *url) {
    Node *n = malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(n->url, url);
    n->prev = n->next = NULL;
    return n;
}

void visit(const char *url) {
    Node *n = createNode(url);

    // Delete forward history
    if (cur) {
        Node *t = cur->next;
        while (t) {
            Node *tmp = t;
            t = t->next;
            free(tmp);
        }
        cur->next = n;
        n->prev = cur;
    }

    cur = n;
    printf("Visited: %s\n", url);
}

void back(int steps) {
    while (steps-- > 0 && cur && cur->prev)
        cur = cur->prev;
    printf("Current page: %s\n", cur ? cur->url : "None");
}

void forward(int steps) {
    while (steps-- > 0 && cur && cur->next)
        cur = cur->next;
    printf("Current page: %s\n", cur ? cur->url : "None");
}

void show() {
    if (!cur) {
        printf("No browsing history yet.\n");
        return;
    }
    Node *t = cur;
    while (t->prev) t = t->prev; // Go to start
    printf("\n--- Browser History ---\n");
    while (t) {
        printf("%s%s\n", t->url, (t == cur) ? "  <- current" : "");
        t = t->next;
    }
}

int main() {
    int ch, steps;
    char url[100];

    while (1) {
        printf("\n1.Visit  2.Back  3.Forward  4.Show  5.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;

        switch (ch) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2:
                printf("Enter number of steps back: ");
                scanf("%d", &steps);
                back(steps);
                break;
            case 3:
                printf("Enter number of steps forward: ");
                scanf("%d", &steps);
                forward(steps);
                break;
            case 4:
                show();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
