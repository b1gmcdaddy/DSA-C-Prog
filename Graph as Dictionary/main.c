#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "GraphDict.h"


int main() {
    Dictionary d;
    initDict(&d, 26);

    addVertex(&d, "Japan");
    addVertex(&d, "America");
    addVertex(&d, "England");
    addVertex(&d, "Sweden");

    addEdge(&d, "America", "Japan");
    addEdge(&d, "America", "Sweden");
    addEdge(&d, "America", "England");

    display(d);
    
    removeVertex(&d, "Japan");
    removeEdge(&d, "America", "Sweden");
    printf("After removal: \n");
    display(d);
    BFS(d, "America");

    return 0;
}

