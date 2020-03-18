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
	Node_t *route[];
} Path_t;

/* Function prototypes */

/**
 * Finds the optimal route between two nodes.
 *
 * @param start Initial node.
 * @param end Destination id.
 * @return Calculated results.
 */
Path_t *calculatePath( Node_t *start, unsigned int end );

#endif
