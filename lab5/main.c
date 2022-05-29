#include "Model/general.h"

int type = 0;

void (*func[])(Graph **graph) = {
        NULL,
        cNewVertex,
        cNewEdge,
        cDeleteVertex,
        cDeleteEdge,
        cOutput,
        cPathDFS,
        cBellmanFord,
        cMinimumSpanningTree,
        cGraphViz,
        cCanadaGraph,
        cDeleteCurrent
};

int main() {
    Graph *graph = NULL;
    graph = graphInit(graph);
    type = getTypeOfWeightCalc();
    int choice = controller();
    while (choice) {
        func[choice](&graph);
        choice = controller();
    }
    freeGraph(graph);
    return 0;
}