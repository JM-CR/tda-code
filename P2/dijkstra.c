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

/* Private types */

struct container {
	Node_t *node;
	Node_t *previous;
	bool visited;
	unsigned int sdf;
	struct container *next;
};

typedef struct container Container_t;   // Dijkstra's container

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
 * Creates a container used to track the Dijkstra's state.
 *
 * @param node Node to track.
 * @param previous Previous visited node.
 * @param visited Tracking state.
 * @param sdf Initial shortest distance.
 * @return Pointer to the container.
 */
static Container_t* createContainer( Node_t *node, Node_t *previous, bool visited, unsigned int sdf ) {
	Container_t *container = malloc(sizeof(Container_t));
	container->node = node;
	container->previous = previous;
	container->visited = visited;
	container->sdf = sdf;
	container->next = NULL;
	return container;
}

/**
 * Adds a container at the end of the linked list.
 * 
 * @param root First container.
 * @param next Container to add.
 */
static void addContainer( Container_t *root, Container_t *next ) {
	// Guards
	if ( root == NULL || next == NULL ) {
		return;
	}

	// Find last
	Container_t *current = root;
	while ( current->next != NULL ) {
		current = current->next;
	}
	
	// Add
	current->next = next;
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
 * Finds a container in the linked list.
 * New containers are added to the end of the list.
 *
 * @param root Root container.
 * @param node Node to search.
 * @param createNew Create new container if it does not exist.
 * @return Pointer to the container.
 */
static Container_t *findContainer( Container_t *root, Node_t *node, bool createNew ) {
	// Guards
	if ( node == NULL || root == NULL ) {
		return NULL;
	}
	
	// Traverse list
	Container_t *match = root;
	while ( match->node != node || match != NULL ) {
		match = match->next;
	}

	// Results
	Container_t *result = NULL;
	if ( match == NULL && createNew ) {
		Container_t *temp = createContainer(node, NULL, false, UINT_MAX);
		addContainer(root, temp);
		result = temp;
	} else if ( match != NULL ) {
		result = match;
	}
	return result;
}

/**
 * Implements the dijkstra's algorithm.
 *
 * @param start Starting node.
 * @param end Ending id.
 */
static void dijkstra( Node_t *start, unsigned int end ) {
	
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Path_t *calculatePath( Node_t *start, unsigned int end ) {
	// Guards
	if ( start == NULL || start->id == end ) {
		return NULL;
	}
	
	// Initialize elements
	Node_t *base = tempGraph();
	start = base;

	// Processing
	dijkstra(start, end);

	// Save results
	Path_t *path = malloc(sizeof(Path_t));
	path->sdf = 0;
	path->route = NULL;
	return path;
}
