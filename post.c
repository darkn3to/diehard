#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct stack {
    char data;
    struct stack *next;
}s;
void push (s **stackhead, char val) {
    s *node=(s *)malloc(sizeof(s));
    node->data=val;
    node->next=NULL;
    if (!*stackhead) {
        *stackhead=node;
    }
    else {
        node->next=*stackhead;
        *stackhead=node;
    }
}
char pop (s **stack) {
    s *temp=(*stack);
    *stack=(*stack)->next;
    return temp->data;
}
char peek (s **stack) {
    return (*stack)->data;
}
int prec(char ch1) {
    switch (ch1) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '(': return 0;
    }
}
int isOperator (char c) {
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')') return 1;
    return 0;
}
void main() {
    s *stack=NULL;
    int i = 0, j = 0;
    char infix[50], postfix[50];
    printf("Enter an expression: ");
    scanf("%s", infix);
    while (infix[i] != '\0') {
        char token = infix[i];
        if (isalpha(token) || isdigit(token)) {
            postfix[j++] = token;
        } else if (isOperator(token)) {
            while (stack && prec(peek(&stack)) >= prec(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (1) {
                pop(&stack); 
            } else {
                printf("Unbalanced parentheses.\n");
                exit(1);
            }
        }
        i++;
    }
    while (stack != NULL) {
        if (peek(&stack) == '(') {
            printf("Unbalanced parentheses.\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    printf("The postfix expression: %s", postfix);
 
}