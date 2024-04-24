#include <stdio.h>
#include <malloc.h>
#include "graph.c"

void dfs(GRAPH *graph, int *visited, STACK *stack, int vrt) {
    //dfs of the vertex with push in stack
    *(visited + vrt) = 1;
    NODE *tmp = graph->list[vrt];

    while (tmp != NULL) {
        if (*(visited + tmp->vertex) == 0)
            dfs(graph, visited, stack, tmp->vertex);
        tmp = tmp->next;
    }
    push(stack, vrt);
}

GRAPH *transform(GRAPH *graph) {
    //the function of inverting this graph
    GRAPH *tGraph = createGraph(graph->numVertices);
    for (int i = 0; i < graph->numVertices; ++i) {
        NODE *tmp = graph->list[i];

        while (tmp != NULL) {
            int nextVrt = tmp->vertex;
            addEdge(tGraph, nextVrt + 1, i + 1);
            tmp = tmp->next;
        }
    }
    return tGraph;
}

int *init(int n) {
    //the function of filling the array with zeros
    int *visited = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        *(visited + i) = 0;
    return visited;
}

void kosaraju(GRAPH *graph) {
    int *visited = init(graph->numVertices);
    GRAPH *invertG;
    STACK *priority, *res;
    priority = createStck(-1);
    res = createStck(-1);

    for (int i = 0; i < graph->numVertices; ++i) {
        if (*(visited + i) == 0)
            dfs(graph, visited, priority, i);
    }

    invertG = transform(graph);

    visited = init(graph->numVertices);

    for (int i = 0; i < graph->numVertices; ++i) {
        int vert = pop(priority);
        if (*(visited + vert) == 0) {
            dfs(invertG, visited, res, vert);
            printStck(res);
            clearStack(res);
        }
    }

    free(visited);
    clearGraph(invertG);
}

int main() {
    int n, m, start, end;

    scanf("%d", &n);
    scanf("%d", &m);
    GRAPH *graph = createGraph(n);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    kosaraju(graph);

    clearGraph(graph);
    return 0;
}
