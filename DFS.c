#include <stdio.h>
#include <limits.h>
#include "cs4050.h"
#include "DFS.h"

// Recursive function to visit vertices during DFS traversal
void DFS_VISIT(Vertex * V, int countV, Edge * E, int countE, int u, int * pTime)
{
    // Increment time and mark the discovery time for the current vertex
    (*pTime)++;
    V[u].d = *pTime;
    V[u].color = GRAY;  // Mark the vertex as "visited" (GRAY)

    // Traverse the adjacency list of the current vertex
    Adjacency * Adj = V[u].list;
    while (Adj)
    {
        Vertex * v = &(V[Adj->pEdge->to - 1]);

        // Check if the graph is undirected (or handle the reverse edge)
        if (1)  // Placeholder condition for checking if the graph is undirected
        {
            if (u == Adj->pEdge->to - 1)
            {
                v = &(V[Adj->pEdge->from - 1]);  // Handle undirected edge
            }
        }

        // If the adjacent vertex is unvisited (WHITE), recursively visit it
        if (v->color == WHITE)
        {
            v->predecessor = V[u].number;  // Set predecessor to current vertex
            DFS_VISIT(V, countV, E, countE, v->number - 1, pTime);  // Recur on adjacent vertex
        }

        Adj = Adj->next;  // Move to the next adjacent vertex
    }

    // Increment time and mark the finish time for the current vertex
    (*pTime)++;
    V[u].f = *pTime;
    V[u].color = BLACK;  // Mark the vertex as "finished" (BLACK)

    // Print the current vertex's number (in DFS finish order)
    printf("%d ", V[u].number);
}

// Function to perform DFS on all vertices in the graph
void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    printf("DFS:\n");

    // Initialize all vertices by setting them to WHITE and resetting their discovery times and predecessors
    for (int i = 0; i < countV; i++)
    {
        V[i].color = WHITE;  // Mark all vertices as unvisited (WHITE)
        V[i].d = 0;          // Reset discovery time
        V[i].predecessor = 0; // Clear predecessor
    }

    int time = 0;  // Initialize the time counter

    // Loop through all vertices and start DFS from any unvisited (WHITE) vertex
    for (int i = 0; i < countV; i++)
    {
        if (V[i].color == WHITE)
        {
            DFS_VISIT(V, countV, E, countE, i, &time);  // Visit the vertex using DFS
        }
    }

    printf("\n\n");  // Add newline after traversal is printed
}



