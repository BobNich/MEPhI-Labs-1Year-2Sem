#include "graphvizLib.h"

void graphViz(Graph *graph) {

    makeDefaultVisited(graph);

    FILE *file = fopen("Graph.dot", "w");
    fprintf(file, "digraph {\nedge [dir=none];\n");
    fclose(file);
    writeNodes(graph);
    file = fopen("Graph.dot", "a+");
    fprintf(file, "}");
    fclose(file);
    system("D:\\Graphviz\\bin\\dot.exe Graph.dot -Tpng -o Graph.png");
}

void writeNodes(Graph *graph) {
    if (!graph) return;
    FILE *file = fopen("Graph.dot", "a+");

    for (int i = 0; i < graph->size; i++) {
        char *id = graph->node[i]->vertex->id;
        fprintf(file, "\"%s\";\n", id);
        Node *curNode = graph->node[i];
        curNode->vertex->visited = true;
        for (int j = 0; j < curNode->size; j++) {
            if (curNode->edges[j]->nodePtr->vertex->visited == false || curNode->edges[j]->nodePtr == curNode) {
                fprintf(file, "\"%s\" -> \"%s\"[label = %.*f];\n", id, curNode->edges[j]->nodePtr->vertex->id, 3,
                        curNode->edges[j]->weight);
            }
        }
    }

    fclose(file);
}
