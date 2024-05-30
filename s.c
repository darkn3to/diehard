#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    char data;
    struct stack *next;
} s;

void push(s **h, char c) {
    if (c == ' ')
        return;
    else {
        s *temp = (s *)malloc(sizeof(s));
        temp->data = c;
        temp->next = *h;
        *h = temp;
    }
}

void print(s *h) {
    s *curr = h;
    char *output = NULL;
    int length = 0;

    // Calculate the length of the stack
    while (curr) {
        length++;
        curr = curr->next;
    }

    // Allocate memory for the output string
    output = (char *)malloc(length + 1);

    // Fill the output string by popping from the stack
    curr = h;
    for (int i = 0; i < length; i++) {
        output[i] = curr->data;
        curr = curr->next;
    }

    // Null-terminate the output string
    output[length] = '\0';

    // Print the reversed string
    printf("%s\n", output);

    // Free the allocated memory
    free(output);
}

int main() {
    char str[50], *ptr;
    printf("Enter the expression: ");
    scanf("%s", str);
    ptr = str;
    s *head = NULL;
    char c;
    while (*ptr != '\0') {
        c = *ptr;
        push(&head, c);
        ptr++;
    }
    print(head);
    return 0;
}
