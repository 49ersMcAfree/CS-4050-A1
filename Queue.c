#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

// Function to create a new queue
Queue * createQueue()
{
    Queue * Q = malloc(sizeof(Queue));  // Allocate memory for the queue
    Q->front = NULL;  // Initialize front to NULL
    Q->back = NULL;   // Initialize back to NULL
    return Q;
}

// Function to create a new node for the queue
Node * createNode()
{
    Node * node = malloc(sizeof(Node));  // Allocate memory for the node
    node->item = NULL;  // Initialize item to NULL
    node->next = NULL;  // Initialize next to NULL
    return node;
}

// Function to add an item to the queue (enqueue)
void Enqueue(Queue * Q, void * item)
{
    Node * node = createNode();  // Create a new node
    node->item = item;           // Set the node's item to the given item

    // Insert the node at the back of the queue
    if (Q->back == NULL)  // If the queue is empty
    {
        Q->front = node;  // Set both front and back to the new node
        Q->back = node;
    }
    else
    {
        node->next = Q->back;  // Attach the current back node to the new node
        Q->back = node;        // Move the back pointer to the new node
    }
}

// Function to remove an item from the queue (dequeue)
void * Dequeue(Queue * Q)
{
    if (IsEmptyQueue(Q))  // If the queue is empty, return NULL
    {
        return NULL;
    }

    Node * node = Q->front;  // Get the front node
    Node * prev = Q->back;   // Get the back node

    // Traverse to the node just before the front
    while (prev && prev->next != node)
    {
        prev = prev->next;
    }

    // If only one element is left in the queue
    if (prev == node)
    {
        Q->back = NULL;
        Q->front = NULL;
    }
    else if (prev && prev->next == node)
    {
        prev->next = NULL;   // Remove the link to the front node
        Q->front = prev;     // Move front to the previous node
    }

    void * item = node->item;  // Store the item to return
    free(node);                // Free the memory of the dequeued node
    return item;
}

// Function to check if the queue is empty
int IsEmptyQueue(Queue * Q)
{
    return (Q == NULL || Q->front == NULL);  // Queue is empty if front is NULL
}

// Recursive function to print the nodes in the queue
void PrintNodes(Node * node)
{
    if (node != NULL)
    {
        PrintNodes(node->next);  // Recursively print next nodes
        printf("x");  // Print 'x' for each node
    }
}

// Function to print the entire queue
void PrintQueue(Queue * Q)
{
    PrintNodes(Q->back);  // Print nodes starting from the back
    printf("\n");         // Newline after the queue is printed
}

// Function to destroy the queue and free memory
void DestroyQueue(Queue * Q)
{
    while (!IsEmptyQueue(Q))  // Dequeue until the queue is empty
    {
        Dequeue(Q);
    }
    free(Q);  // Free the queue itself
}