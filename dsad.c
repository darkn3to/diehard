#include <stdio.h>
#include <stdlib.h>

typedef struct sl {
    int data;
    struct sl *next;
} sl;

typedef struct dl {
    int data;
    struct dl *next;
    struct dl *prev;
} dl;

void createSinglyList(sl **head) {
    if (*head) {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid number.\n");
        return;
    }
    sl *curr = NULL;
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        sl *temp = (sl *)malloc(sizeof(sl));
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (!*head)
            *head = curr = temp;
        else {
            curr->next = temp;
            curr = curr->next;
        }
    }
}

void print(sl *h1, dl *h2, int c) {
    if (c == 404) {
        sl *head = h1;
        while (head) {
            printf("%d ", head->data);
            head = head->next;
        }
    } 
    else if (c == 403) {
        dl *head = h2;
        while (head) {
            printf("%d ", head->data);
            head = head->next;
        }
    } 
    else {
        printf("Invalid choice.\n");
    }
    printf("\n");
    system("pause");
}
void insertAtBeginSingly(sl **head, int value) {
    sl *temp = (sl *)malloc(sizeof(sl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void insertAtEndSingly(sl **head, int value) {
    sl *curr = *head, *temp = (sl *)malloc(sizeof(sl));
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
        curr = curr->next;

    curr->next = temp;
}

void insertAfterkSingly(sl **head, int value, int k) {
    sl *curr = *head, *temp = (sl *)malloc(sizeof(sl));
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
    while (curr->next && curr->data != k)
        curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
}

void insertBeforekSingly(sl **head, int value, int k) {
    sl *curr = *head, *temp = (sl *)malloc(sizeof(sl));
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

void deleteBeginSingly(sl **head) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    sl *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEndSingly(sl **head) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    sl *temp;
    sl *curr = *head;
    if (!(*head)->next) {
        *head = (*head)->next;
        free(curr);
        return;
    }
    while (curr->next->next != NULL)
        curr = curr->next;
    temp = curr->next;
    curr->next = NULL;
    free(temp);
}

void deletekSingly(sl **head, int k) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    sl *temp;
    sl *curr = *head;
    if ((*head)->data == k) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (curr->next && curr->next->data != k)
        curr = curr->next;
    if (curr->next) {
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    } else
        printf("%d does not exist in the list.\n", k);
}

void createDoublyList(dl **head) {
    if (*head) {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid number.\n");
        return;
    }
    dl *curr = NULL;
    for (int i = 0; i < n; i++) {
        dl *temp = (dl *)malloc(sizeof(dl));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        temp->prev = NULL;
        if (!*head) {
            *head = curr = temp;
        } else {
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
        }
    }
}

void printDoublyList(dl *head) {
    if (!head)
        printf("List is empty.\n");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    system("pause");
}

void insertAtBeginDoubly(dl **head, int val) {
    dl *temp = (dl *)malloc(sizeof(dl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->prev = NULL;
    temp->next = *head;
    if (*head) {
        (*head)->prev = temp;
    }
    *head = temp;
}

void insertAtEndDoubly(dl **head, int val) {
    dl *temp = (dl *)malloc(sizeof(dl));
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
    dl *curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
}

void insertAfterkDoubly(dl **head, int val, int k) {
    dl *temp = (dl *)malloc(sizeof(dl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head) {
        temp->next = temp->prev = NULL;
        *head = temp;
        return;
    }
    dl *curr = *head;
    while (curr->next && curr->data != k)
        curr = curr->next;
    temp->prev = curr;
    temp->next = curr->next;
    if (curr->next) {
        curr->next->prev = temp;
    }
    curr->next = temp;
}

void insertBeforekDoubly(dl **head, int val, int k) {
    dl *temp = (dl *)malloc(sizeof(dl));
    if (!temp) {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head) {
        temp->next = temp->prev = NULL;
        *head = temp;
        return;
    }
    dl *curr = *head;
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

void deleteBeginDoubly(dl **head) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    dl *temp = *head;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteEndDoubly(dl **head) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    dl *temp;
    if ((*head)->next == NULL) {
        temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    dl *curr = *head;
    while (curr->next)
        curr = curr->next;
    temp = curr;
    curr->prev->next = NULL;
    free(temp);
}

void deletekDoubly(dl **head, int k) {
    if (!*head) {
        printf("List already empty!\n");
        return;
    }
    dl *temp;
    if ((*head)->data == k) {
        temp = *head;
        *head = (*head)->next;
        if (*head) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    dl *curr = *head;
    while (curr && curr->data != k)
        curr = curr->next;
    if (curr) {
        temp = curr;
        curr->prev->next = curr->next;
        if (curr->next) {
            curr->next->prev = curr->prev;
        }
        free(temp);
    }
}

int main() {
    sl *head = NULL;
    dl *doublyHead = NULL;
    int choice, value, k, ltype;
    printf("1. Singly Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ltype);

    switch (ltype) {
        case 1:
            while (1) {
                system("cls");
                printf("\nLinked List Operations Menu:\n");
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
                            sl *temp = head;
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
                system("cls");
                printf("Doubly Linked List Operations Menu:\n");
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
                            dl *temp = doublyHead;
                            doublyHead = doublyHead->next;
                            free(temp);
                        }
                        exit(0);
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
            case 3:
                exit(0);
    }
}