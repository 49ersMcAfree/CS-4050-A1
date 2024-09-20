#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Enqueue an element
void enqueue(Queue* queue, int value) {
    // Create a new node
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    
    // If queue is empty, both front and rear are the new node
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    // Add the new node to the end of the queue
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Dequeue an element
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty
    }
    
    // Get the front node
    QueueNode* temp = queue->front;
    int value = temp->data;

    // Move the front to the next node
    queue->front = queue->front->next;

    // If front becomes NULL, set rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    // Free the dequeued node and return its value
    free(temp);
    return value;
}

// Check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Free the queue memory
void freeQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}


