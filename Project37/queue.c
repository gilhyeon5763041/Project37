#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 15

typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

QueueType q;

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return (q->rear == q->front);
}

int is_full(QueueType* q) {
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("큐가 포화상태\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("큐가 공백상태\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element front(QueueType* q) {
    if (is_empty(q)) {
        printf("큐가 공백상태\n");
        return -1;
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


int main(void) {
    int a = 0;
    int Item = 0;
    init_queue(&q);

    while (1) {
        printf("===== MENU =====\n");
        printf("1. Input data and Enqueue\n");
        printf("2. Dequeue and Print data\n");
        printf("3. Print front data\n");
        printf("4. Exit\n");
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &Item);
            enqueue(&q, Item);
        }
        if (a == 2) {
            printf("%d\n", dequeue(&q));
        }
        if (a == 3) {
            if (is_empty(&q)) {
                printf("Queue is empty\n");
            }
            else {
                printf("Queue(front=%d rear=%d): ", q.front, q.rear);
                int i = q.front;
                do {
                    i = (i + 1) % MAX_QUEUE_SIZE;
                    printf("%d ", q.data[i]);
                } while (i != q.rear);
                printf("\n");
            }
        }
        if (a == 4) {
            break;
        }
    }
}