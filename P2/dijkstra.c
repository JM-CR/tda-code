// See dijkstra.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: dijkstra.c
// Date: 15/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "dijkstra.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

/* Private types */

/* Private global variables */

/* Private functions */

/**
 * Creates a temporal graph; used to test the algorithm.
 *
 * @return Pointer to the root node.
 */
static Node_t *tempGraph( void ) {
	// Create nodes
	Node_t **node = calloc(5, sizeof(Node_t));
	node[0] = newNode(1, 0, NULL, 4, 0);
	node[1] = newNode(2, 1, NULL, 4, 0);
	node[2] = newNode(3, 6, NULL, 4, 0);
	node[3] = newNode(4, 2, NULL, 4, 0);
	node[4] = newNode(5, 4, NULL, 4, 0);

	// Connect first node
	setSlot(&node[0], &node[1], DOWN);
	setSlot(&node[0], &node[2], RIGHT);

	// Connect second node
	setSlot(&node[1], &node[0], UP);
	setSlot(&node[1], &node[2], DOWN);
	setSlot(&node[1], &node[3], RIGHT);

	// Connect third node
	setSlot(&node[2], &node[0], LEFT);
	setSlot(&node[2], &node[1], UP);
	setSlot(&node[2], &node[3], DOWN);
	setSlot(&node[2], &node[4], RIGHT);

	// Connect forth node
	setSlot(&node[3], &node[1], LEFT);
	setSlot(&node[3], &node[2], UP);
	setSlot(&node[3], &node[4], RIGHT);

	// Connect fifth node
	setSlot(&node[4], &node[2], UP);
	setSlot(&node[4], &node[3], DOWN);

	return node[0];
}

/**
 * Allocates memory for an array and initializes its values.
 *
 * @param value Value to set.
 * @param total Number of elements create.
 * @return Array with the initial values.
 */
static unsigned int *allocateWith( unsigned int value, size_t total ) {
	unsigned int *array = calloc(total, sizeof(int));
	for ( unsigned int i = 0; i < total; ++i ) {
		array[i] = value;
	}
	return array;
}

/**
 * Checks if a node has already been visited.
 *
 * @param id Node to check.
 * @param visited All the visited nodes.
 * @param size Number of elements in the visited array.
 * @return True if the node has been visited; otherwise false
 */
static bool visitedNode( unsigned int id, unsigned int visited[], size_t size ) {
	bool flag = false;
	for ( unsigned int i = 0; i < size; ++i ) {
		if ( *(visited + i) == id ) {
			flag = true;
			break;
		}
	}
	return flag;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Path_t *calculatePath( Node_t *baseNode, size_t totalNodes, unsigned int from, unsigned int to ) {
	// Guards
	if ( baseNode == NULL || totalNodes == 0 || from == to ) {
		return NULL;
	}
	
	// Initialize elements
	Node_t *base = tempGraph();
	unsigned int *sdf = allocateWith(UINT_MAX, totalNodes);
	unsigned int *previous = allocateWith(0, totalNodes);
	unsigned int *visited = allocateWith(0, totalNodes);

	// Save results
	Path_t *path = malloc(sizeof(Path_t));
	path->sdf = *sdf;
	path->route = previous;
	return path;
}
