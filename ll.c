#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} a;

void create(a **, int);
void deleteak(a **);
void insert0(a **);
void delete5(a **);
void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a *head = NULL;
    if (n == 0) {
        printf("List is empty.");
    } else {
        for (int i = 0; i < n; i++) {
            create(&head, i+1);
        }
    }
    /*insert0(&head);
    deleteak(&head);*/
    delete5(&head);
    a *curr = head;
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

void create(a **h, int n) {
    a *nn = (a *)malloc(sizeof(a));
    nn->data = n;
    nn->next = NULL;
    /*nn->prev=NULL;
    if (!*h) {
        *h=nn;
    }
    else {
        a *curr=*h;
        while (curr->next) {
            curr=curr->next;
        }
        curr->next=nn;
        nn->prev=curr;
    }*/
    
    if (!*h) {
        *h = nn; 
    } else {
        a *curr = *h;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = nn;
    }
}

/*void deleteak(a **h) {
    a *curr=*h;
    while (curr) {
        if ((curr->data)%5==0) {
            a *temp=curr;
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
        }
        curr=curr->next;
    }
}*/
void insert0(a** h) {
    a* curr = *h;
    while (curr->next) {
        if ((curr->next->data) % 5 == 0) {
            a* new_node = (a*)malloc(sizeof(a));
            new_node->data = 0;
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next; // Skip the newly inserted node
        } 
        else curr=curr->next;
    }
}
void delete5 (a **h) {
    a *curr=*h;
    while (curr->next) {
        if ((curr->next->data)%5==0) 
        {
            a *temp=curr->next;
            curr->next=curr->next->next;
            free(temp);
        }
        else curr=curr->next;
    }
}