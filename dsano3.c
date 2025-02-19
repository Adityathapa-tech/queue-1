

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Queue structure
struct Queue {
    int items[SIZE];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(struct Queue *q) {
    return q->rear == SIZE - 1;
}

// Enqueue operation
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {  // Reset queue when last element is removed
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Peek operation
int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Display queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    display(&q);

    printf("Peek: %d\n", peek(&q));

    dequeue(&q);
    display(&q);

    return 0;
}