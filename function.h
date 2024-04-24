#define GRAPH struct graph
#define NODE struct node
#define STACK struct stack

STACK {
    //structure of stack надо подумать вдруг можно просто стек с вершинами
    int vertex;
    STACK *next;
};

NODE {
    //structure of node to describe vertex
    int vertex;
    NODE *next;
};

GRAPH {
    //the list of node's lists
    int numVertices;
    NODE **list;
};

STACK *createStck(int vertex);

NODE *createNode(int vertex);

GRAPH *createGraph(int numVert);

void printStck(STACK *stack);

void push(STACK *stack, int vrt);

int empty(STACK *stack);

int pop(STACK *elem);

void addEdge(GRAPH *graph, int start, int end);

void printGraph(GRAPH *graph);

void clearNode(NODE *node);

void clearGraph(GRAPH *graph);

void clearStack(STACK *stack);

