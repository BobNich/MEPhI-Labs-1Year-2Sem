#ifndef LAB4_BINTREELIB_H
#define LAB4_BINTREELIB_H
#include "general.h"

Graph *graphInit(Graph *graph);

int findVertexByID(Graph *graph, char *id);
int findVertexByCoord(Graph *graph, int x, int y);
Node *searchNodeByID(Graph *graph, char *id);
Node *searchNodeByCoords(Graph *graph, int x, int y);

Graph *newVertex(Graph *graph, Vertex *vertex);
Vertex *createVertex(char *id, int x, int y);

Graph *newEdge(Graph *graph, char *i1, char *i2, double (*calcWeight) (Vertex *first, Vertex *second));
void createEdge(Graph *graph, int iF, int iS, double (*calcWeight) (Vertex *first, Vertex *second));

void deleteLink(Node *node1, Node *node2, int count);
Graph *deleteVertex(Graph *graph, char *id);
Graph *deleteEdge(Graph *graph, char *idF, char *idS, int count);

void dfs(Graph *graph, Node *current, int *i);
Vector *pathDFS(Graph *graph, Node *node1, Node *node2);
Vector *bellmanFord(Graph *graph, int start, int end);
Graph *minimumSpanningTree(Graph *graph, Graph *newGraph, double (*calcWeight)(Vertex *first, Vertex *second));

void outputGraph(Graph *graph);

void freeGraph(Graph *graph);
void freeVertex(Node *node);

double calcWeightCartesian(Vertex *first, Vertex *second);
double calcWeightLatitudeLongitude(Vertex *first, Vertex *second);
void displaceNodes(Graph *graph, int iStart, int iEnd, int step);
void makeDefaultVisited(Graph *graph);
int getNumOfRepeated(Node *node1, Node *node2);

#endif
