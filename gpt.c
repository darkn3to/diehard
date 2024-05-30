#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
}n;

n *create(n **h, int no) {
    n *curr = NULL, *fn = NULL;
    if (no == 0) {
        printf("The number of nodes can't be zero.\n");
        return NULL;
    } else {
        printf("Enter the list elements: ");
        for (int i = 0; i < no; i++) {
            n *temp = (n *)malloc(sizeof(n));
            scanf("%d", &(temp->data));
            temp->next = NULL;
            temp->prev = NULL;
            if (!*h) {
                *h = temp;
                curr = temp;
                fn = temp;
            } else {
                curr->next = temp;
                temp->prev = curr;
                curr = curr->next;
            }
            curr->next = fn;
            fn->prev = curr;
        }
    }
    return curr;
}

void printtt(n *he) {
    n *currr = he;
    do {
        printf("%d ", currr->data);
        currr = currr->next;
    } while (currr != he);
    printf("\n");
}

void deleteallk(n **head, int k) {
    if (*head == NULL)
        return;

    n* current = *head;
    n* temp = NULL;

    do {
        if (current->data == k) {
            temp = current;

            if (current->next == current) {
                // If there's only one node in the list
                *head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (*head == current)
                    *head = current->next;
            }

            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    } while (current != *head);
}
void removekth(n **h, int k) {
    n *curr=*h;
    
}
void main() {
    n *head=NULL;
    int no;
    printf("Enter the number of nodes: ");
    scanf("%d", &no);
    n *tail=create(&head, no);
    removekth(&head, 5);
    printtt(head);
}