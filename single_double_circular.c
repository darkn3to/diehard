#include <stdio.h>
#include <stdlib.h>
typedef struct l1 {
    int data;
    struct l1* next;
}sl;
typedef struct l2 {
    int data;
    struct l2* next, * prev;
}dl;
void createList(sl** head) {
    if (*head) {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n==0) {
        printf("Number of nodes can't be zero.\n");
        return;
    }
    sl* curr = NULL;
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        sl* temp = (sl*)malloc(sizeof(sl));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (!*head) {
            *head = temp;
            curr = temp;
        }
        else {
            curr->next = temp;
            curr = curr->next;
        }
    }
}
void print(sl *h1, dl *h2, int c) {
    if (c==404) {
        sl *head = h1;
        while (head) {
            printf("%d ", head->data);
            head = head->next;
        }
    } 
    else if (c==403) {
        dl *head = h2;
        while (head) {
            printf("%d ", head->data);
            head = head->next;
        }
    } 
    else if (c==402) {
        dl *head = h2;
        dl* curr = head;
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != head);
        printf("\n");
    }
    else printf("Invalid choice.\n");
    printf("\n");
}
void insertAtBegin(sl** head, int value) {
    sl* temp = (sl*)malloc(sizeof(sl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = *head;
    *head = temp;
}
void insertAtEnd(sl** head, int value) {
    sl* curr = *head, * temp = (sl*)malloc(sizeof(sl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (!*head) {
        *head = temp;
        return;
    }
    while (curr->next)
        curr->next = temp;
    curr->next = temp;
}
void insertAfterk(sl** head, int value, int k) {
    sl* curr = *head, * temp = (sl*)malloc(sizeof(sl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (!*head) {
        *head = temp;
        return;
    }
    while (curr->next && curr->data != k) curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
}
void insertBeforek(sl** head, int value, int k) {
    sl* curr = *head, * temp = (sl*)malloc(sizeof(sl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (!*head || (*head)->data == k) {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (curr->next) {
        if (curr->next->data == k) {
            temp->next = curr->next;
            curr->next = temp;
            return;
        }
        curr = curr->next;
    }
    temp->next = *head;
    *head = temp;
}
void deleteBegin(sl** head) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    sl* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteEnd(sl** head) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    sl* temp = *head, * curr = *head;
    if (!(*head)->next) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (curr->next->next != NULL) curr = curr->next;
    temp = curr->next;
    curr->next = NULL;
    free(temp);
}
void deletek(sl** head, int k) {
    if (!*head) {
        printf("List is empty!\n");
        return;
    }
    sl* temp, * curr = *head;
    if ((*head)->data == k) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (curr->next && curr->next->data != k) curr = curr->next;
    if (curr->next) {
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    else printf("%d does not exist in the list.\n", k);
}
void createDoublyList(dl** head) {
    if (*head) {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n==0) {
        printf("The number of nodes can't be zero.");
        return;
    }
    dl* curr = NULL;
    printf("Enter the list elements: ");
    for (int i = 0; i < n; i++) {
        dl* temp = (dl*)malloc(sizeof(dl));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (!*head) {
            *head=temp;
            curr=temp;
            curr->prev=NULL;
        } 
        else {
            dl *dummy=curr;
            curr->next=temp;
            curr=curr->next;
            curr->prev=dummy;
        }
    }
}
void insertAtBeginDoubly(dl** head, int val) {
    dl* temp = (dl*)malloc(sizeof(dl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->prev = NULL;
    temp->next = *head;
    if (*head) (*head)->prev = temp;
    *head = temp;
}
void insertAtEndDoubly(dl** head, int val) {
    dl* temp = (dl*)malloc(sizeof(dl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->next = NULL;
    if (!*head) {
        temp->prev = NULL;
        *head = temp;
        return;
    }
    dl* curr = *head;
    while (curr->next) curr->next = temp;
    curr->next = temp;
}
void insertAfterkDoubly(dl** head, int val, int k) {
    dl* temp = (dl*)malloc(sizeof(dl));
    temp->data = val;
    if (!*head) {
        temp->next = temp->prev = NULL;
        *head = temp;
        return;
    }
    dl* curr = *head;
    while (curr->next && curr->data != k) curr = curr->next;
    temp->prev = curr;
    temp->next = curr->next;
    if (curr->next) {
        curr->next->prev = temp;
    }
    curr->next = temp;
}
void insertBeforekDoubly(dl** head, int val, int k) {
    dl* temp = (dl*)malloc(sizeof(dl));
    temp->data = val;
    if (!*head) {
        temp->next = temp->prev = NULL;
        *head = temp;
        return;
    }
    dl* curr = *head;
    while (curr->next) {
        if (curr->next->data == k) {
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
            temp->prev = curr;
            return;
        }
        curr = curr->next;
    }
    temp->next = *head;
    temp->prev = NULL;
    (*head)->prev = temp;
    *head = temp;
}
void deleteBeginDoubly(dl** head) {
    if (!*head) {
        printf("List is empty.\n");
        return;
    }
    dl* temp = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(temp);
}
void deleteEndDoubly(dl** head) {
    if (!*head) {
        printf("List is empty.\n");
        return;
    }
    dl* temp;
    if ((*head)->next == NULL) {
        temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    dl* curr = *head;
    while (curr->next)
        curr->next = curr->next;
    temp = curr;
    curr->next = NULL;
    free(temp);
}
void deletekDoubly(dl** head, int k) {
    if (!*head) {
        printf("List is empty!\n");
        return;
    }
    dl* temp;
    if ((*head)->data == k) {
        temp = *head;
        *head = (*head)->next;
        if (*head) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    dl* curr = *head;
    while (curr && curr->data != k) curr = curr->next;
    if (curr) {
        temp = curr;
        curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        free(temp);
    }
}
void createCircularList(dl** head) {
    if (*head) {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n==0) {
        printf("Number of nodes can't be zero.\n");
        return;
    }
    dl* curr = NULL;
    dl* firstNode = NULL; 
    for (int i = 0; i < n; i++) {
        dl* temp = (dl*)malloc(sizeof(dl));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        temp->prev = NULL;
        if (!*head) {
            *head = curr = temp;
            firstNode = temp; 
        }
        else {
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
        }
    }
    if (firstNode) {
        curr->next = firstNode;
        firstNode->prev = curr;
    }
}
void insertAtBeginCircular(dl** head, int val) {
    dl* newNode = (dl*)malloc(sizeof(dl));
    newNode->data = val;
    if (!*head) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    }
    else {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode; 
    }
}
void insertAtEndCircular(dl** head, int val) {
    dl* newNode = (dl*)malloc(sizeof(dl));
    newNode->data = val;
    if (!*head) {
        newNode->next = newNode->prev = newNode; 
        *head = newNode;
    }
    else {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}
void insertAfterValueCircular(dl** head, int val, int afterVal) {
    dl* newNode = (dl*)malloc(sizeof(dl));
    newNode->data = val;
    if (!*head) {
        printf("List is empty. Insertion not possible.\n");
        free(newNode);
        return;
    }
    dl* curr = *head;
    do {
        if (curr->data == afterVal) {
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next->prev = newNode;
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    } while (curr != *head);
    printf("%d not found in the list. Insertion not possible.\n", afterVal);
    free(newNode);
}
void insertBeforeValueCircular(dl** head, int val, int beforeVal) {
    dl* newNode = (dl*)malloc(sizeof(dl));
    newNode->data = val;
    if (!*head) {
        printf("List is empty. Insertion not possible.\n");
        free(newNode);
        return;
    }
    dl* curr = *head;
    do {
        if (curr->data == beforeVal) {
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
            if (curr == *head) {
                *head = newNode;
            }
            return;
        }
        curr = curr->next;
    } while (curr != *head);
    printf("%d not found in the list. Insertion not possible.\n", beforeVal);
    free(newNode);
}
void deleteBeginCircular(dl** head) {
    if (!*head) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    dl* toDelete = *head;
    if (toDelete->next == toDelete) {
        *head = NULL; 
    }
    else {
        *head = toDelete->next; 
        toDelete->prev->next = *head;
        (*head)->prev = toDelete->prev;
    }
    free(toDelete);
}
void deleteEndCircular(dl** head) {
    if (!*head) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    dl* toDelete = (*head)->prev;
    if (toDelete->prev == toDelete) {
        *head = NULL;
    }
    else {
        (*head)->prev = toDelete->prev; 
        toDelete->prev->next = *head;
    }
    free(toDelete);
}
void deleteValueCircular(dl** head, int val) {
    if (!*head) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    dl* curr = *head;
    do {
        if (curr->data == val) {
            if (curr == *head) {
                *head = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            return;
        }
        curr = curr->next;
    } while (curr != *head);
    printf("%d not found in the list. Deletion not possible.\n", val);
}
void printCircularList(dl* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    dl* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}
void display() {
    printf("1. Create a List\n");
    printf("2. Print the List\n");
    printf("3. Insert at the Beginning\n");
    printf("4. Insert at the End\n");
    printf("5. Insert After a Value\n");
    printf("6. Insert Before a Value\n");
    printf("7. Delete from the Beginning\n");
    printf("8. Delete from the End\n");
    printf("9. Delete a Value\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}
void main() {
    sl* head = NULL;
    dl* doublyHead = NULL;
    int choice, value, k, ltype;
    printf("1. Singly Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Circular Linked List\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ltype);
    switch (ltype) {
    case 1:
        while (1) {
            display();
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                print(head, NULL, 404);
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBegin(&head, value);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value after which to insert: ");
                scanf("%d", &k);
                insertAfterk(&head, value, k);
                break;
            case 6:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value before which to insert: ");
                scanf("%d", &k);
                insertBeforek(&head, value, k);
                break;
            case 7:
                deleteBegin(&head);
                break;
            case 8:
                deleteEnd(&head);
                break;
            case 9:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deletek(&head, value);
                break;
            case 10:
                while (head != NULL) {
                    sl* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
        break;
    case 2:
        while (1) {
            display();
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                createDoublyList(&doublyHead);
                break;
            case 2:
                print(NULL, doublyHead, 403);
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginDoubly(&doublyHead, value);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEndDoubly(&doublyHead, value);
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value after which to insert: ");
                scanf("%d", &k);
                insertAfterkDoubly(&doublyHead, value, k);
                break;
            case 6:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value before which to insert: ");
                scanf("%d", &k);
                insertBeforekDoubly(&doublyHead, value, k);
                break;
            case 7:
                deleteBeginDoubly(&doublyHead);
                break;
            case 8:
                deleteEndDoubly(&doublyHead);
                break;
            case 9:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deletekDoubly(&doublyHead, value);
                break;
            case 10:
                while (doublyHead != NULL) {
                    dl* temp = doublyHead;
                    doublyHead = doublyHead->next;
                    free(temp);
                }
                exit(0);
            default: printf("Invalid choice. Please try again.\n");
            }
        }
    case 3:
        while (1) {
            display();
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                createCircularList(&doublyHead);
                break;
            case 2:
                print(NULL, doublyHead, 402);
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginCircular(&doublyHead, value);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEndCircular(&doublyHead, value);
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value after which to insert: ");
                scanf("%d", &k);
                insertAfterValueCircular(&doublyHead, value, k);
                break;
            case 6:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the value before which to insert: ");
                scanf("%d", &k);
                insertBeforek(&head, value, k);
                break;
            case 7:
                deleteBeginCircular(&doublyHead);
                break;
            case 8:
                deleteEndCircular(&doublyHead);
                break;
            case 9:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteValueCircular(&doublyHead, k);
                break;
            case 10:
                while (doublyHead != NULL) {
                    dl* temp = doublyHead;
                    doublyHead = doublyHead->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
        break;
    case 4: exit(0);
    default:
        printf("Invalid choice. Please try again.\n");
    }
}