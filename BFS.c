#include <stdio.h>
#include <limits.h>
#include "Queue.h"
#include "BFS.h"

// Helper function to initialize vertex properties
void initializeVertices(Vertex * V, int countV, int startVertex) {
    for (int i = 0; i < countV; i++) {
        if (V[i].number == startVertex) {
            V[i].color = GRAY;
            V[i].d = 0;
            V[i].predecessor = 0;
        } else {
            V[i].color = WHITE;
            V[i].d = INT_MAX;
            V[i].predecessor = 0;
        }
    }
}

// Helper function to process the adjacency list and enqueue the neighbors
void processAdjacencyList(Vertex *V, Vertex *u, Queue *Q) {
    Adjacency *Adj = V[u->number - 1].list;
    while (Adj) {
        Vertex *v = &(V[Adj->pEdge->to - 1]);

        // Handling for undirected graphs: swap if necessary
        if (v->number == u->number) {
            v = &(V[Adj->pEdge->from - 1]);
        }

        // If the vertex hasn't been visited (is white), mark and enqueue it
        if (v->color == WHITE) {
            v->color = GRAY;
            v->d = u->d + 1;
            v->predecessor = u->number;
            Enqueue(Q, v);
        }
        Adj = Adj->next;
    }
}

void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s) {
    printf("\nBFS:\n");

    // Initialize vertices with proper colors, distances, and predecessors
    initializeVertices(V, countV, s);

    // Create a queue for BFS and enqueue the start vertex
    Queue *Q = createQueue();
    Enqueue(Q, &(V[s - 1]));

    // BFS main loop
    while (!IsEmptyQueue(Q)) {
        // Dequeue the next vertex and print it
        Vertex *u = (Vertex *)Dequeue(Q);
        printf("%d ", u->number);

        // Process all adjacent vertices of the dequeued vertex
        processAdjacencyList(V, u, Q);

        // Mark the vertex as fully processed (black)
        u->color = BLACK;
    }

    // Clean up the queue after BFS completes
    DestroyQueue(Q);
    printf("\n\n");
}
