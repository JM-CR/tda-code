// Optimal route between nodes using the Dijkstra's algorithm.
// Author: Josue Mosiah Contreras Rocha
// File: dijkstra.h
// Date: 15/03/20

// -----------------------------
// System headers
// -----------------------------
#include "graph.h"

// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

typedef struct path {
	unsigned int sdf;
	unsigned int *route;
} Path_t;

/* Function prototypes */

/**
 * Finds the optimal route between two nodes.
 *
 * @param baseNode Root node.
 * @param from Starting id.
 * @param to Ending id.
 * @return Calculated results.
 */
Path_t *calculatePath( Node_t *baseNode, unsigned int from, unsigned int to );
