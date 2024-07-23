#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void push(Stack *s, char value);
char pop(Stack *s);
int isEmpty(Stack *s);
int isOperand(char ch);
int precedence(char ch);
void infixToPrefix(char infix[], char prefix[]);
void infixToPostfix(char infix[], char postfix[]);

// Main function
void main() {
    char infix[MAX_SIZE] = "(a+b)*c/(d+e)";
    char prefix[MAX_SIZE], postfix[MAX_SIZE];
    clrscr();
    infixToPrefix(infix, prefix);
    infixToPostfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Prefix expression: %s\n", prefix);
    printf("Postfix expression: %s\n", postfix);
    getch();
}

// Function to push an element onto the stack
void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

// Function to get precedence of operators
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    Stack stack;
    int i, j;
    stack.top = -1;
    i=0;
    j=0;
    strrev(infix); // Reverse the infix expression
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ')')
            push(&stack, infix[i]);
        else if (infix[i] == '(') {
            while (stack.top != -1 && stack.items[stack.top] != ')')
                prefix[j++] = pop(&stack);
            if (stack.top != -1)
                pop(&stack);
        } else if (isOperand(infix[i]))
            prefix[j++] = infix[i];
        else {
            while (stack.top != -1 && precedence(infix[i]) < precedence(stack.items[stack.top]))
                prefix[j++] = pop(&stack);
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(&stack))
        prefix[j++] = pop(&stack);
    prefix[j] = '\0';
    strrev(prefix); // Reverse the prefix expression to get the actual result
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    int i, j ;
    stack.top = -1;
    i = 0;
    j=0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            push(&stack, infix[i]);
        else if (infix[i] == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(')
                postfix[j++] = pop(&stack);
            if (stack.top != -1)
                pop(&stack);
        } else if (isOperand(infix[i]))
            postfix[j++] = infix[i];
        else {
            while (stack.top != -1 && precedence(infix[i]) <= precedence(stack.items[stack.top]))
                postfix[j++] = pop(&stack);
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(&stack))
        postfix[j++] = pop(&stack);
    postfix[j] = '\0';
}