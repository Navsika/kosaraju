#include <stdio.h>
#include <malloc.h>
#include "graph.h"

STACK *createStck(int vertex) {
    //create a stack
    STACK *stack;
    stack = (STACK *) malloc(sizeof(STACK));
    stack->vertex = vertex;
    stack->next = 0;
    return stack;
}

NODE *createNode(int vertex) {
    //create a vertex of graph
    NODE *newNode = malloc(sizeof(NODE));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

GRAPH *createGraph(int numVert) {
    //create graph with creation of lists
    GRAPH *newGraph = malloc(sizeof(GRAPH));
    newGraph->numVertices = numVert;

    newGraph->list = malloc(numVert * sizeof(NODE *));
    for (int i = 0; i < numVert; ++i)
        newGraph->list[i] = NULL;
    return newGraph;
}

void addEdge(GRAPH *graph, int start, int end) {
    //add edge between two vertex (
    //an directed graph)
    NODE *node = createNode(end - 1);
    node->next = graph->list[start - 1];
    graph->list[start - 1] = node;
}

void printGraph(GRAPH *graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        NODE *temp = graph->list[i];
        printf("%d: ", i + 1);
        while (temp != NULL) {
            printf("%d ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

void clearNode(NODE *node) {
    //clear of node
    if (node->next != NULL)
        clearNode(node->next);
    free(node);
}

void clearGraph(GRAPH *graph) {
    //clear of graph
    for (int i = 0; i < graph->numVertices; ++i) {
        clearNode(graph->list[i]);
    }
    free(graph);
}

void printStck(STACK *stack) {
    //function to print scc
    printf("scc: ");
    STACK *tmp = stack->next;
    while (tmp) {
        printf("%d ", (tmp->vertex) + 1);
        tmp = tmp->next;
    }
    printf("\n");
}

void push(STACK *stack, int vrt) {
    //to insert element in stack
    STACK *elem = createStck(vrt);
    STACK *first = stack->next;
    elem->next = first;
    stack->next = elem;
}

int empty(STACK *stack) {
    //check of the stack
    if (stack->next)
        return 0;
    return 1;
}

int pop(STACK *elem) {
    //removes an item from the stack and returns it
    if (!empty(elem)) {
        STACK *old = elem->next;
        elem->next = old->next;
        int vrt = old->vertex;
        free(old);
        return vrt;
    }
    return 0;
}

void clearStack(STACK *stack) {
    //clear of stack
    while (!empty(stack))
        pop(stack);
}
