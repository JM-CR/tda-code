// Graph simulator.
// Author: Josue Mosiah Contreras Rocha
// Author: Gabriela Rojano
// File: main.c
// Date: 07/03/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"

int main(void) {
	// Dijkstra's test
	Node_t *root = tempGraph();
	Path_t *bestPath = calculatePath(root, 5);
	printPath(bestPath);
    return 0;
}
