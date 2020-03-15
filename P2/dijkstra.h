// Optimal route between nodes using the Dijkstra's algorithm.
// Author: Josue Mosiah Contreras Rocha
// File: dijkstra.h
// Date: 15/03/20

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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
 * @param start Initial node.
 * @param totalNodes Number of nodes in the graph.
 * @param end Destination id.
 * @return Calculated results.
 */
Path_t *calculatePath( Node_t *start, size_t totalNodes, unsigned int end );

#endif
