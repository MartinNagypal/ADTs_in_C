//
// Created by Martin Nagypal on 08.11.26.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct Queue {
    node *head;
}Queue;

Queue *queue() {
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->head = NULL;
    return newQueue;
}

void enqueue(Queue *queue, int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if (queue->head == NULL) {
        queue->head = n;
        return;
    }
    node *current = queue->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = n;
}

void dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return;
    }
    if (queue->head->next == NULL) {
        free(queue->head);
        queue->head = NULL;
        return;
    }

    node *newHead = queue->head->next;
    free(queue->head);
    queue->head = newHead;
}

node *head(Queue *queue) {
    if (queue->head == NULL)
        return NULL;

    return queue->head;
}

int isEmpty(Queue *queue) {
    return queue->head == NULL;
}

void printList(Queue *queue) {
    printf("-----Queue----- \n");
    if (queue->head == NULL) {
        printf("Queue is Empty \n");
        printf("--------------- \n");
        return;
    }
    for (node *p = queue->head; p != NULL; p = p->next)
        printf("%d\n", p->data);

    printf("--------------- \n");
}

int main() {
    Queue *queue1 = queue();
    enqueue(queue1, 1);
    enqueue(queue1, 2);
    enqueue(queue1, 3);
    printList(queue1);
    dequeue(queue1);
    printList(queue1);
    dequeue(queue1);
    enqueue(queue1, 5);
    enqueue(queue1, 8);
    printList(queue1);

    return 0;
}