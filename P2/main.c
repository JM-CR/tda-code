// Graph simulator.
// Author: Josue Mosiah Contreras Rocha
// Author: Gabriela Rojano
// File: main.c
// Date: 07/03/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include "graph.h"
#include "dijkstra.h"

int main(void) {
	// Create
	int cols = 5;
	int rows = 1;
	Node_t *root = createGraph(rows, cols);

	// Dijkstra's test
	Path_t *path = calculatePath(root, cols * rows, 1, 4);

    return 0;
}
