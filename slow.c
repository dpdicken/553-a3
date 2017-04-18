#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

Node *head;

void insert(int toAdd) {

    Node *cur = head;
    
    if (cur == NULL) {
        cur = malloc(sizeof(Node));
        cur->next = NULL;
        cur->data = toAdd;
        head = cur;
        return;
    }

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = malloc(sizeof(Node));
    cur->next->next = NULL;
    cur->next->data = toAdd;

}

int findLen() {

    int len = 0;
    Node *cur = head;

    while (cur != NULL) {
        cur = cur->next;
        len++;
    }

    return len;

}

int findMax() {

    int max = 0;
    Node *cur = head;

    while (cur != NULL) {

        if (cur->data > max) {
            max = cur->data;
        }

        cur = cur->next;

    }

    return max;

}

int findAvg() {

    unsigned long sum = 0;
    Node *cur = head;

    while (cur != NULL) {
        
        sum += cur->data;
        cur = cur->next;

    }

    return sum / findLen();

}

int read() {

    int read;
    int rc = scanf("%d", &read);

    if (rc == EOF) {
        return 0;
    }
    return read;

}

int main () {

    int input;
    head = NULL;

    while ((input = read())) {
        insert(input);
    }
    
    printf("Length: %d\n", findLen());
    printf("Max: %d\n", findMax());
    printf("Avg: %d\n", findAvg());

}
