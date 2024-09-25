#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef __cplusplus
extern "C" 
{
#endif
// Data types

typedef struct Node{
    void * item;
    struct Node * next;
} Node;


typedef struct Queue{
    Node * front;
    Node * back;
} Queue;


//Prototypes
Queue * createQueue();
Node * createNode();
void Enqueue(Queue * Q, void * item);
void * Dequeue(Queue * Q);
int IsEmptyQueue(Queue * Q);
void PrintNodes(Node * nodelist);
void PrintQueue(Queue * Q);
void DestroyQueue(Queue * Q);


#ifdef __cplusplus

#endif

#endif
