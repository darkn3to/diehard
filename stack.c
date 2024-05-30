#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
    int data;
    struct stack* next;
}s;
typedef struct Stack {
    int data[5];
    int top;
}as;
void pushlist(s** h, int x) {
    s* ptr = (s*)malloc(sizeof(s));
    ptr->data = x;
    if (!*h) {
        ptr->next = NULL;
    } else {
        ptr->next = *h;
    }
    *h = ptr;
}
void poplist(s** h) {
    if (!*h) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    s* temp = *h;
    *h = (*h)->next;
    free(temp);
}
int isEmptySinglyLinkedList(s* h) {
    return h == NULL ? 1 : 0;
}
void pusharray(as* stack, int val) {
    if (stack->top == 5) {
        printf("Stack Overflow.\n");
        return;
    }
    stack->data[stack->top++] = val;
}
void poparray(as* stack) {
    if (stack->top == 0) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    stack->top--;
}
int isFullArrayStack(as* stack) {
    return stack->top == 5;
}
void print(s** h) {
    s* curr = *h;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
void printas(as* st) {
    for (int i = 0; i < st->top; i++) {
        printf("%d ", st->data[i]);
    }
    printf("\n");
}
void main() {
    s* head = NULL;
    as st;
    st.top = 0;
    int choice, value, ch;
    printf("1. Stack using linked list.\n");
    printf("2. Stack using array\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            while (1) {
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Print\n");
                printf("4. Is Empty\n");
                printf("5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("Enter the value to push: ");
                        scanf("%d", &value);
                        pushlist(&head, value);
                        break;
                    case 2:
                        poplist(&head);
                        break;
                    case 3:
                        printf("Stack: ");
                        print(&head);
                        printf("\n");
                        break;
                    case 4:
                        if (isEmptySinglyLinkedList(head)) {
                            printf("Stack is empty.\n");
                        } else {
                            printf("Stack is not empty.\n");
                        }
                        break;
                    case 5:
                        while (head != NULL) {
                            poplist(&head);
                        }
                        exit(0);
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
            break;
        case 2:
            while (1) {
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Print\n");
                printf("4. Is Full\n");
                printf("5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("Enter the value to push: ");
                        scanf("%d", &value);
                        pusharray(&st, value);
                        break;
                    case 2:
                        poparray(&st);
                        break;
                    case 3:
                        printas(&st);
                        break;
                    case 4:
                        if (isFullArrayStack(&st)) {
                            printf("Stack is full.\n");
                        } else {
                            printf("Stack is not full.\n");
                        }
                        break;
                    case 5:
                        exit(0);
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
    }
}
