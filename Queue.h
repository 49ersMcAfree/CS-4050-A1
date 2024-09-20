#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef __cplusplus
extern "C" 
{
#endif

//put your prototypes here
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define the queue structure
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);
void freeQueue(Queue* queue);


#ifdef __cplusplus

#endif

#endif
