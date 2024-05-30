#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};



void insert(struct node **head) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
struct node* current;
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        current = newnode;
    } else {
        current->next = newnode;
        current = newnode;
    }
}

int sum(struct node *head) {
    int sum_result = 0;
    struct node* ctr = head;
    while (ctr != NULL) {
        sum_result += ctr->data;
        ctr = ctr->next;
    }
    return sum_result;
}

int main() {
    int i, n;
    struct node* head = NULL; 
    printf("Enter the number of elements for nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        insert(&head);
    }
    int result = sum(head);
    printf("Sum of elements: %d\n", result);
    return 0;
}