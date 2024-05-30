#include <stdio.h>
#include <stdlib.h>
/*typedef struct node {
    int data;
    struct node *next;
}n;*/
typedef struct node {
    int data;
    struct node *prev, *next;
}n;
/*void create(n **h, int no) {
    if (no==0) {
        printf("The number of nodes can't be zero.");
        return;
    }
    else {
        printf("Enter the list elements: ");
        n *curr=NULL;
        for (int i=0; i<no; i++) {
            n *temp=(n *)malloc(sizeof(n));
            scanf("%d", &(temp->data));                
            temp->next=NULL;
            if (!*h) {
                *h=temp;
                curr=temp;
            } 
            else {
                curr->next=temp;
                curr=curr->next;
            }
        }
    }
}
n *create(n **h, int no) {
    static n *curr=NULL;
    if (no==0) {
        printf("The number of nodes can't be zero.");
        return NULL;
    }
    else {
        printf("Enter the list elements: ");
        for (int i=0; i<no; i++) {
            n *temp=(n *)malloc(sizeof(n));
            scanf("%d", &(temp->data));                
            temp->next=NULL;
            if (!*h) {
                *h=temp;
                curr=temp;
                curr->prev=NULL;
            } 
            else {
                n *dummy=curr;
                curr->next=temp;
                curr=curr->next;
                curr->prev=dummy;
            }
        }
    }
    return curr;
}*/
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
/*void print(n *h) {
    n *c=h;
    while (c) {
        printf("%d ", c->data);
        c=c->next;
    }
    printf("\n");
}
void printt(n *t) {
    n *cc=t;
    while (cc) {
        printf("%d ", cc->data);
        cc=cc->prev;
    }
}*/
void printtt(n *he) {
    n *currr = he;
    do {
        printf("%d ", currr->data);
        currr = currr->next;
    } while (currr != he);
    printf("\n");
}
/*void deleteEnd(n **tail) {
    n *h=(*tail)->next;
    n *tailprev=(*tail)->prev;
    n *temp=(*tail);
    tailprev->next=h;
    free(temp);
}*/
void deleteallk(n **head, int k) {
    if (*head == NULL)
        return;

    n* current = *head;
    n* temp;

    do {
        if (current->data == k) {
            temp = current->next;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            current = temp;
        } else {
            current = current->next;
        }
    } while (current != *head);
}
void main() {
    n *head=NULL;
    int no;
    printf("Enter the number of nodes: ");
    scanf("%d", &no);
    n *tail=create(&head, no);
    /*print(head);*/
    deleteallk(&head, 69);
    printtt(head);
}