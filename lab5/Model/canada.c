#include "../Model/general.h"


Graph *buildCanadaGraph(Graph *graph, FILE *file, int num) {
    char * numTmp = getStrFile(file);

    if (num > atoi(numTmp)) {
        printf("Maximum number of cities = %d\n", atoi(numTmp));
        free(numTmp);
        return graph;
    }

    char **name = calloc(sizeof(char *), (num + 1));
    char *x, *y;

    for (int i = 0; i < num; i++) {
        name[i] = getStrFile(file);
        x = getStrFile(file);
        y = getStrFile(file);
        newVertex(graph, createVertex(name[i], atoi(x), atoi(y)));
        free(x);
        free(y);
        if (i > 0) {
            for (int j = 0; j < i; j++) {
                newEdge(graph, name[i], name[j], calcWeightLatitudeLongitude);
            }
        }
    }

    free(name);
    free(numTmp);
    return graph;
}