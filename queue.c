#include <stdio.h>
#include <stdlib.h>
typedef struct Q {
    int *elements;
    int capacity;
    int front, rear;
    int size;
}q;
q* createQ(int capacity) {
    q* Q = (q *)malloc(sizeof(q));
    Q->capacity = capacity;
    Q->elements = (int *)malloc(sizeof(int)*capacity);
    Q->front = Q->rear = -1;
    Q->size = 0;
    return Q;
}
int isFull(q* Q) {
    return (Q->size == Q->capacity);
}
int isEmpty(q* Q) {
    return (Q->size == 0);
}
void enqueue(q* Q, int item) {
    if (isFull(Q)) {
        printf("Q is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(Q))
        Q->front = 0;
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->elements[Q->rear] = item;
    Q->size++;
}
int dequeue(q* Q) {
    if (isEmpty(Q)) {
        printf("Q is empty. Cannot dequeue.\n");
        return -1; 
    }
    int item = Q->elements[Q->front];
    if (Q->front == Q->rear)
        Q->front = Q->rear = -1;
    else
        Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;
    return item;
}
void print(q* Q) {
    if (isEmpty(Q)) {
        printf("Q is empty.\n");
        return;
    }
    printf("Q elements: ");
    int i = Q->front;
    while (1) {
        printf("%d ", Q->elements[i]);
        if (i == Q->rear)
            break;
        i = (i + 1) % Q->capacity;
    }
    printf("\n");
}
void main() {
    q* Q = createQ(5); 
    int choice, value;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(Q, value);
                break;
            case 2:
                value = dequeue(Q);
                if (value != -1) printf("Dequeued element: %d\n", value);
                break;
            case 3:
                print(Q);
                break;
            case 4:
                free(Q);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
