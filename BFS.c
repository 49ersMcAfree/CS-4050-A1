#include <stdio.h>
#include <limits.h>
#include "cs4050.h"
#include "Queue.h"
#include "BFS.h"
//breath first search algorithm
void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
     // Initialize visited array to track which vertices have been visited
    int visited[countV];
    for (int i = 0; i < countV; i++) {
        visited[i] = 0;  // Mark all vertices as not visited
    }

    // Create a queue for BFS
    Queue *q = createQueue();

    // Start BFS from vertex 's'
    visited[s] = 1;  // Mark the starting vertex as visited
    enqueue(q, s);   // Enqueue the starting vertex

    while (!isQueueEmpty(q)) {
        // Dequeue a vertex from the queue
        int current = dequeue(q);
        printf("Visited Vertex: %d\n", current);  // Print the vertex

        // Explore all the neighbors of the dequeued vertex
        for (int i = 0; i < countE; i++) {
            // Adjust according to correct field names for Edge
            if (E[i].from == current && visited[E[i].to] == 0) {
                visited[E[i].to] = 1;  // Mark as visited
                enqueue(q, E[i].to);   // Enqueue the neighbor vertex
            }
        }
    }

    // Free the queue after BFS completes
    freeQueue(q);
}
