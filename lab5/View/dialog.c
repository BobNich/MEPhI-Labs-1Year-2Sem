#include "../Model/general.h"

const char *msgs[] = {
        "Exit",
        "Add Vertex",
        "Add Edge between two Vertices",
        "Delete Vertex",
        "Delete Edge",
        "Graph Output (Adjacency Lists)",
        "Path between two Vertices",
        "Bellman-Ford Algorithm",
        "Minimum Spanning Tree",
        "Graph Visualise",
        "Build Canada Cities Graph",
        "Delete current Graph"
};

const char *calcType[] = {
        "Latitude/Longitude",
        "Cartesian"
};

const int NC = sizeof(calcType) / sizeof (calcType[0]);
const int N = sizeof(msgs) / sizeof(msgs[0]);

int optionsView() {
    printf("---------------------------------\n");
    for (int i = 0; i < N; i++){
        printf("%d: %s\n", i, msgs[i]);
    }
    printf("---------------------------------\n");
    printf("->");
    return N;
}

char * getCurrentID(int number) {
    printf("ID of the Vertex %d:\n", number);
    return get_str();
}
void getCoords(int *x, int *y) {
    printf("X-coordinate:\n");
    *x = getInt(0);
    printf("Y-coordinate:\n");
    *y = getInt(0);
}

int getCanadaCitiesNumber() {
    printf("Number of cities:\n");
    int num = getInt(1);
    return num;
}

char *getFileName() {
    printf("File name:\n");
    return get_str();
}

int getTypeOfWeightCalc() {
    for (int i = 0; i < NC; i++) printf("%d: %s\n", i, calcType[i]);
    printf("->\n");
    int type = getInt(1);
    if (type >= NC) return getTypeOfWeightCalc();
    return type;
}