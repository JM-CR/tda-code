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

#define VISIT_MASK 0x10

/* Private global variables */

static Node_t **vertex;
static Node_t **previous;
static unsigned int *sdf;
static unsigned int TOTAL;

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
 * @param total Number of elements create.
 * @return Array with the initial values.
 */
static unsigned int *allocateZero( size_t total ) {
	unsigned int *array = calloc(total, sizeof(int));
	for ( unsigned int i = 0; i < total; ++i ) {
		array[i] = UINT_MAX;
	}
	return array;
}

/**
 * Allocates memory for an array and initializes its values.
 *
 * @param total Number of elements create.
 * @return Array with the initial values.
 */
static Node_t **allocateNull( size_t total ) {
	Node_t **array = calloc(total, sizeof(Node_t));
	for ( unsigned int i = 0; i < total; ++i ) {
		array[i] = NULL;
	}
	return array;
}

/**
 * Marks a node as visited.
 *
 * @param node Node to set.
 */
static void setVisit( Node_t **node ) {
	// Update node
	(*node)->c_state |= VISIT_MASK;
}

/**
 * Checks if a node has been visited.
 *
 * @param node Node to check.
 * @return True if the node was visited; otherwise, false.
 */
static bool wasVisited( Node_t *node ) {
	return (node->c_state & VISIT_MASK) == VISIT_MASK ? true : false;
}

/**
 * Calculates the cost between two nodes.
 *
 * @param first First node.
 * @param second Second node.
 * @return Path cost.
 */
static unsigned int pathCost( Node_t *first, Node_t *second ) {
	int total = first->cost - second->cost;
	return abs(total);
}

/**
 * Looks for a node in the vertex array.
 *
 * @param node Node to search.
 * @return Array's position; otherwise, -1.
 */
static int getPosition( Node_t *node ) {
	unsigned int position = -1;
	for ( unsigned int i = 0; i < TOTAL; ++i ) {
		if ( node == vertex[i] ) {
			position = i;
			break;
		}
	}
	return position;
}

/**
 * Inserts a node in the vertex array.
 * 
 * @param node Node to insert.
 */
static void insertVertex( Node_t *node ) {
	static unsigned int lastIndex = 0;
	vertex[lastIndex++] = node;
}

/**
 * Implementes the dijkstra's algorithm.
 *
 * @param start Starting node.
 * @param end Ending id.
 */
static void process( Node_t *start, unsigned int end ) {

}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Path_t *calculatePath( Node_t *start, size_t totalNodes, unsigned int end ) {
	// Guards
	if ( start == NULL || totalNodes == 0 || start->id == end ) {
		return NULL;
	}
	
	// Initialize elements
	Node_t *base = tempGraph();
	TOTAL = totalNodes;
	sdf = allocateZero(totalNodes);
	vertex = allocateNull(totalNodes);
	previous = allocateNull(totalNodes);

	// Dijkstra
	process(base, end);

	// Save results
	Path_t *path = malloc(sizeof(Path_t));
	path->sdf = *sdf;
	path->route = NULL;
	return path;
}
