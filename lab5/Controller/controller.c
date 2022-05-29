#include "../Model/general.h"

double (*calc[])(Vertex *first, Vertex *second) = {
        calcWeightLatitudeLongitude,
        calcWeightCartesian
};

int controller() {
    int choice;
    int N = optionsView();
    do {
        choice = getInt(0);
        if (choice < 0 || choice >= N) {
            errors(1);
        }
    } while (choice < 0 || choice >= N);
    return choice;
}

void cNewVertex(Graph **graph) {
    int x, y;
    char *id = getCurrentID(1);
    getCoords(&x, &y);

    bool resID = searchNodeByID(*graph, id);
    bool resCoords = searchNodeByCoords(*graph, x, y);

    if (!(resID || resCoords)) newVertex(*graph, createVertex(id, x, y));
    else {
        free(id);
        errors(3);
    }
}

void cNewEdge(Graph **graph) {
    char *idF = getCurrentID(1);
    char *idS = getCurrentID(2);

    if (!newEdge(*graph, idF, idS, calcWeightCartesian)) errors(2);

    free(idF);
    free(idS);
}

void cDeleteVertex(Graph **graph) {
    char *id = getCurrentID(1);
    searchNodeByID(*graph, id) != NULL ? deleteVertex(*graph, id) : errors(2);
    free(id);
}

void cDeleteEdge(Graph **graph) {
    char *idF = getCurrentID(1);
    char *idS = getCurrentID(2);

    bool resF = searchNodeByID(*graph, idF);
    bool resS = searchNodeByID(*graph, idS);

    (resF && resS) ? deleteEdge(*graph, idF, idS, 1) : errors(2);

    free(idF);
    free(idS);
}

void cOutput(Graph **graph) {
    if ((*graph)->size == 0) {
        errors(2);
        return;
    }
    outputGraph(*graph);
}

void cGraphViz(Graph **graph) {
    if ((*graph)->size == 0) {
        errors(2);
        return;
    }
    graphViz(*graph);
}

void cCanadaGraph(Graph **graph) {
    FILE *file;
    freeGraph(*graph);
    *graph = graphInit(*graph);
    if (!(file = fopen("canada.txt", "r"))) {
        errors(5);
        return;
    }
    int num = getCanadaCitiesNumber();
    buildCanadaGraph(*graph, file, num);
}

void cPathDFS(Graph **graph) {
    char *idF = getCurrentID(1);
    char *idS = getCurrentID(2);
    int index1 = findVertexByID(*graph, idF);
    int index2 = findVertexByID(*graph, idS);
    if (index1 == -1 || index2 == -1) {
        errors(4);
        return;
    }

    makeDefaultVisited(*graph);
    Vector *path;
    path = pathDFS(*graph, (*graph)->node[index1], (*graph)->node[index2]);

    if (path != NULL) {
        printf("%s -> ", idF);
        for (int i = path->size - 1; i > 1; i--) printf("%s -> ", path->data[i]->vertex->id);
        printf("%s\n", path->data[0]->vertex->id);
    }
    free(path);

    free(idF);
    free(idS);
}

void cBellmanFord(Graph **graph) {
    char *idF = getCurrentID(1);
    int index1 = findVertexByID(*graph, idF);
    char *idS = getCurrentID(2);
    int index2 = findVertexByID(*graph, idS);
    Vector *path;

    if (index1 == -1 || index2 == -1) {
        errors(4);
        return;
    }

    Vector *pathEnd = vectorInit(0, NULL);
    path = bellmanFord(*graph, index1, index2);

    for (int v = index2; v != index1; v = findVertexByID(*graph, path->data[v]->vertex->id)){
        if (path->data[v] == NULL) {
            free(path);
            free(pathEnd);
            errors(4);
            return;
        }
        vectorPush(pathEnd, path->data[v]);
    }

    for (int v = pathEnd->size - 1; v >= 0; v--) {
        printf("%s -> ", pathEnd->data[v]->vertex->id);
    }
    printf("%s\n", idS);

    free(path);
}

void cMinimumSpanningTree(Graph **graph) {
    int i = 0;
    Graph *newGraph = NULL;
    newGraph = graphInit(newGraph);

    if ((*graph)->size == 0) {
        errors(2);
        return;
    }

    makeDefaultVisited(*graph);
    dfs(*graph, (*graph)->node[0], &i);

    extern int type;

    if (i == (*graph)->size) {
        newGraph = minimumSpanningTree(*graph, newGraph, calc[type]);
    }
    else errors(4);

    outputGraph(newGraph);
    graphViz(newGraph);
    freeGraph(newGraph);
}

void cDeleteCurrent(Graph **graph) {
    freeGraph(*graph);
    *graph = graphInit(*graph);
    extern int type;
    type = getTypeOfWeightCalc();
}