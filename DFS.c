#include <stdio.h>
#include <limits.h>
#include "cs4050.h"
#include "DFS.h"

// Helper function for DFS traversal
void DFSVisit(Vertex * vertices, int v, Edge * E, int countE) {
    vertices[v].color = GRAY;  // Mark the vertex as in progress
    printf("Visited Vertex: %d\n", v);  // Print the current vertex

    // Explore all edges to find neighbors
    for (int i = 0; i < countE; i++) {
        if (E[i].from == v) {  // Updated field for the source vertex
            int neighbor = E[i].to;  // Updated field for the destination vertex
            if (vertices[neighbor].color == WHITE) {
                vertices[neighbor].predecessor = v;
                DFSVisit(vertices, neighbor, E, countE);
            }
        }
    }

    vertices[v].color = BLACK;  // Mark the vertex as fully explored
}

void PrintDFS(Vertex * V, int countV, Edge * E, int countE) {
    int i;
    Vertex * vertices = V;

    // Initialize vertices
    for (i = 0; i < countV; i++){
        vertices[i].color = WHITE;  // WHITE means unvisited
        vertices[i].predecessor = -1;  // -1 means no predecessor
    }

    // Perform DFS for all vertices
    for (i = 0; i < countV; i++) {
        if (vertices[i].color == WHITE) {
            DFSVisit(vertices, i, E, countE);
        }
    }

    // Print all vertices after DFS completes
    PrintVertices(vertices, countV);
}

