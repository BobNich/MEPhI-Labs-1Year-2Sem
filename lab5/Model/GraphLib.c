#include "general.h"

#define INF 2147483647

Graph *graphInit(Graph *graph) {
    graph = malloc(sizeof(Graph));
    graph->size = 0;
    graph->node = NULL;
    return graph;
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->node[i]->size; j++) {
            free(graph->node[i]->edges[j]);
        }
        if (graph->node[i]->size > 0) free(graph->node[i]->edges);
        freeVertex(graph->node[i]);
        free(graph->node[i]);
    }
    free(graph->node);
    free(graph);
}

void freeVertex(Node *node) {
    free(node->vertex->id);
    free(node->vertex);
}

Vertex *createVertex(char *id, int x, int y) {
    Vertex *new = malloc(sizeof(Vertex));
    new->id = id;
    new->x = x;
    new->y = y;
    new->visited = false;
    return new;
}

Node *createNode(Vertex *vertex) {
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->size = 0;
    return newNode;
}

Graph *newVertex(Graph *graph, Vertex *vertex) {
    graph->size++;

    if (!graph->node) graph->node = malloc(sizeof(Node *));
    else graph->node = realloc(graph->node, graph->size * sizeof(Node *));

    graph->node[graph->size - 1] = createNode(vertex);
    return graph;
}

Graph *newEdge(Graph *graph, char *idF, char *idS, double (*calcWeight)(Vertex *first, Vertex *second)) {
    int i1 = findVertexByID(graph, idF);
    int i2 = findVertexByID(graph, idS);
    if (i1 == -1 || i2 == -1) return graph;

    createEdge(graph, i1, i2, calcWeight);
    if (i1 == i2) return graph;
    createEdge(graph, i2, i1, calcWeight);
    return graph;
}

void createEdge(Graph *graph, int i1, int i2, double (*calcWeight)(Vertex *first, Vertex *second)) {
    Node *node1 = graph->node[i1];
    Node *node2 = graph->node[i2];

    if (node1->size == 0) node1->edges = malloc(sizeof(Edge *));
    else node1->edges = realloc(node1->edges, sizeof(Edge *) * (node1->size + 1));

    node1->edges[node1->size] = malloc(sizeof(Edge));
    node1->edges[node1->size]->nodePtr = node2;
    node1->edges[node1->size]->weight = calcWeight(graph->node[i1]->vertex, graph->node[i2]->vertex);

    node1->size++;
}

Graph *deleteVertex(Graph *graph, char *id) {
    Node *node1 = searchNodeByID(graph, id);

    for (int i = 0; i < node1->size; i++) {
        Node *node2 = node1->edges[i]->nodePtr;
        deleteLink(node2, node1, getNumOfRepeated(node2, node1));
    }

    for (int i = 0; i < node1->size; i++) {
        free(node1->edges[i]);
    }
    free(node1->edges);

    displaceNodes(graph, findVertexByID(graph, node1->vertex->id), graph->size - 1, 1);
    graph->size--;

    freeVertex(node1);
    free(node1);

    return graph;
}

Graph *deleteEdge(Graph *graph, char *idF, char *idS, int count) {
    Node *node1 = searchNodeByID(graph, idF);
    Node *node2 = searchNodeByID(graph, idS);

    if (node1 != node2) deleteLink(node1, node2, count);
    deleteLink(node2, node1, count);

    return graph;
}

void deleteLink(Node *node1, Node *node2, int count) {
    while (count) {
        for (int i = 0; i < node1->size; i++) {
            if (node1->edges[i]->nodePtr == node2) {
                free(node1->edges[i]);
                for (int j = i; j < node1->size - 1; j++) node1->edges[j] = node1->edges[j + 1];
                node1->size--;
            }
        }
        count--;
    }
}

void dfs(Graph *graph, Node *current, int *i) {
    (*i)++;
    current->vertex->visited = true;
    for (int j = 0; j < current->size; j++) {
        if (current->edges[j]->nodePtr->vertex->visited == true) continue;
        dfs(graph, current->edges[j]->nodePtr, i);
    }
}

Vector *pathDFS(Graph *graph, Node *node1, Node *node2) {
    if (node1->vertex == node2->vertex) return vectorInit(1, node1);
    node1->vertex->visited = true;

    for (int i = 0; i < node1->size; i++) {
        if (node1->edges[i]->nodePtr->vertex->visited == true) continue;
        Vector *res = pathDFS(graph, node1->edges[i]->nodePtr, node2);
        if (res != NULL) {
            vectorPush(res, node1->edges[i]->nodePtr);
            return res;
        }
    }

    return NULL;
}

Vector *bellmanFord(Graph *graph, int start, int end) {
    double *dist = malloc(graph->size * sizeof (double));
    Vector *parents = vectorInit(graph->size, NULL);
    for (int i = 0; i < graph->size; i++) dist[i] = INF;
    dist[start] = 0;
    for (int i = 0; i < graph->size - 1; i++) {
        for (int u = 0; u < graph->size; u++) {
            for (int v = 0; v < graph->node[u]->size; v++) {
                if (dist[u] == INF) continue;
                int indexNext = findVertexByID(graph, graph->node[u]->edges[v]->nodePtr->vertex->id);
                double w = graph->node[u]->edges[v]->weight;
                if (dist[indexNext] > dist[u] + w) {
                    dist[indexNext] = dist[u] + w;
                    parents->data[indexNext] = graph->node[u];
                }
            }
        }
    }
    return parents;
}

Graph *minimumSpanningTree(Graph *graph, Graph *newGraph, double (*calcWeight)(Vertex *first, Vertex *second)) {
    makeDefaultVisited(graph);
    int i = 1, j = 0;
    Node *cur, *put;
    newGraph = newVertex(newGraph, createVertex(strdup(graph->node[0]->vertex->id), graph->node[0]->vertex->x,
                                                graph->node[0]->vertex->y));

    while (i < graph->size) {
        double setWeight = INF;
        for (int count = 0; count < newGraph->size; count++) {
            int index = findVertexByID(graph, newGraph->node[count]->vertex->id);
            cur = graph->node[index];
            cur->vertex->visited = true;
            for (int l = 0; l < cur->size; l++) {
                if (cur->edges[l]->weight <= setWeight && cur->edges[l]->nodePtr->vertex->visited == false &&
                    findVertexByID(newGraph, cur->edges[l]->nodePtr->vertex->id) == -1) {
                    setWeight = cur->edges[l]->weight;
                    put = cur->edges[l]->nodePtr;
                    j = count;
                }
            }
        }

        newGraph = newVertex(newGraph, createVertex(strdup(put->vertex->id), put->vertex->x, put->vertex->y));
        newGraph = newEdge(newGraph, put->vertex->id, newGraph->node[j]->vertex->id, calcWeight);
        i++;
    }
    return newGraph;
}

void outputGraph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("%s -> ", graph->node[i]->vertex->id);
        for (int j = 0; j < graph->node[i]->size; j++) {
            printf("%s (%f)-> ", graph->node[i]->edges[j]->nodePtr->vertex->id, graph->node[i]->edges[j]->weight);
        }
        printf("null\n");
    }
}

Node *searchNodeByID(Graph *graph, char *id) {
    int i = findVertexByID(graph, id);
    return (i != -1) ? graph->node[i] : NULL;
}

Node *searchNodeByCoords(Graph *graph, int x, int y) {
    int i = findVertexByCoord(graph, x, y);
    return (i != -1) ? graph->node[i] : NULL;
}

int findVertexByID(Graph *graph, char *id) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->node[i]->vertex->id, id) == 0) return i;
    }
    return -1;
}

int findVertexByCoord(Graph *graph, int x, int y) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->node[i]->vertex->x == x && graph->node[i]->vertex->y == y) return i;
    }
    return -1;
}

double calcWeightCartesian(Vertex *first, Vertex *second) {
    return sqrt(pow(first->x - second->x, 2) + pow(first->y - second->y, 2));
}

double calcWeightLatitudeLongitude(Vertex *first, Vertex *second) {
    double h = sqrt(pow(sin((second->x - first->x) * 0.5), 2) +
                    cos(first->x) * cos(second->x) * pow(sin((second->y - first->y) * 0.5), 2));
    if (h > 1) h = 1;
    if (h == 0) return 0.001;
    return 2 * 6371 * asin(h);
}

void displaceNodes(Graph *graph, int iStart, int iEnd, int step) {
    for (int i = iStart; i < iEnd; i += step) graph->node[i] = graph->node[i + step];
}

void makeDefaultVisited(Graph *graph) {
    for (int i = 0; i < graph->size; i++) graph->node[i]->vertex->visited = false;
}

int getNumOfRepeated(Node *node1, Node *node2) {
    int count = 0;
    for (int j = 0; j < node1->size; j++) if (node1->edges[j]->nodePtr == node2) count++;
    return count;
}
