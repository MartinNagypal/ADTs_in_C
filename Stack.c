//
// Created by Martin Nagypal on 08.11.26.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct Stack {
    node *head;
}Stack;

Stack *stack() {
    Stack *newStack = malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

void push(Stack *stack, int data) {
    if (stack->head == NULL) {
        return;
    }

    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if (stack->head == NULL) {
        stack->head = n;
        return;
    }
    node *current = stack->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = n;
}

void pop(Stack *stack) {
    if (stack->head == NULL) {
        return;
    }

    if (stack->head->next == NULL) {
        node *top = stack->head;
        stack->head = NULL;
        free(top);
        return;
    }

    node *current = stack->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    node *top = current->next;
    current->next = NULL;
    free(top);
}

node *get_top(Stack *stack) {
    if (stack->head == NULL) {
        return NULL;
    }

    node *top = stack->head;
    while (top->next != NULL) {
        top = top->next;
    }
    return top;
}

int isEmpty(Stack *stack) {
    return stack->head == NULL;
}

void printList(Stack *stack) {
    printf("-----Stack----- \n");
    if (stack->head == NULL) {
        printf("Stack is Empty \n");
        printf("--------------- \n");
        return;
    }
    for (node *p = stack->head; p != NULL; p = p->next)
        printf("%d\n", p->data);

    printf("--------------- \n");
}

int main() {
    Stack *newStack = stack();
    push(newStack, 1);
    push(newStack, 2);
    push(newStack, 3);
    printList(newStack);
    node *top = get_top(newStack);
    printf("Top is %d \n", top->data);
    pop(newStack);
    printList(newStack);
    pop(newStack);
    printList(newStack);
    return 0;
}