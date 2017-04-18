#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

Node *head, *tail;

void insert(int toAdd) {

    if (head == NULL){
        head = malloc(sizeof(Node));
        head->next = NULL;
        head->data = toAdd;
        tail = head;
        return;
    } else {
        tail->next = malloc(sizeof(Node));
        tail->next->next = NULL;
        tail->next->data = toAdd;
        tail = tail->next;
        return;
    }


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
