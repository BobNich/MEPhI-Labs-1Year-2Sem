#ifndef LAB4_DIALOG_H
#define LAB4_DIALOG_H

int controller();

void cNewVertex(Graph **graph);
void cNewEdge(Graph **graph);
void cDeleteVertex(Graph **graph);
void cDeleteEdge(Graph **graph);
void cOutput(Graph **graph);
void cPathDFS(Graph **graph);
void cBellmanFord(Graph **graph);
void cMinimumSpanningTree(Graph **graph);
void cGraphViz(Graph **graph);
void cCanadaGraph(Graph **graph);
void cDeleteCurrent(Graph **graph);

#endif
