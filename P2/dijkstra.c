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
#include <stdio.h>
#include "dijkstra.h"


// -----------------------------
// Private elements
// -----------------------------

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
	while ( match != NULL && match->node != node ) {
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
 * Prints the container's content.
 * 
 * @param container Container to print.
 */
static void printContainer( Container_t *container ) {
	// Guard
	if ( container == NULL ) {
		return;
	}

	// Print
	printf("\n-------------------\n");
	printNode(container->node);
	printf("\nSDF: %u", container->sdf);
	printf("\nVisited: %s", container->visited ? "true" : "false");
	if ( container->previous != NULL ) {
		printf("\nPrevious: %d\n", container->previous->id);
	} else {
		printf("\nPrevious: %p\n", container->previous);
	}
}

/**
 * Implements the dijkstra's algorithm.
 *
 * @param start Starting node.
 * @param end Ending id.
 * @return Linked list with the results of the algorithm.
 */
static Container_t *dijkstra( Node_t *start, unsigned int end ) {
	// Initialize
	Node_t *current = start;
	Container_t *root = createContainer(start, NULL, false, 0);
	Direction_t searchOrder[] = { UP, RIGHT, LEFT, DOWN };

	// Find path
	bool found = false;
	while ( !found ) {
		// Look for adjacent nodes
		Node_t *bestAdjacent = NULL;
		Container_t *currentState = findContainer(root, current, true);
		for ( int i = 0, tempSDF = UINT_MAX; i < 4; ++i ) {
			// Guards
			Node_t *adjacent = getAdjacentNode(current, searchOrder[i]);
			Container_t *adjacentState = findContainer(root, adjacent, true);
			if ( adjacent == NULL || adjacentState->visited || current->id == end ) {
				continue;
			}

			// Update values
			unsigned int cost = pathCost(current, adjacent);
			adjacentState->sdf = cost + currentState->sdf;
			adjacentState->previous = current;
			currentState->visited = true;

			// Best cost path
			if ( adjacentState->sdf <= tempSDF && !adjacentState->visited ) {
				bestAdjacent = adjacent;
				tempSDF = adjacentState->sdf;
			}
		}

		// Next iteration
		if ( current->id == end ) {	
			found = true;	
		} else if ( bestAdjacent == NULL ) {
			current = currentState->previous;
		} else {
			current = bestAdjacent;
		}
	}

	return root;
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
	
	// Processing
	Container_t *root = dijkstra(start, end);
	int sdfTotal = 0;
	int i = 0;
	Node_t *nodosTotal[5];
	// Temporal print
	while ( root != NULL ) {
		printContainer(root);
		nodosTotal[i] = root->node;
		i = i +1;
		sdfTotal = sdfTotal + root->sdf;
		root = root->next;
	}
	printf("el numero de nodos es: %d\n",i);

	// Save results
	Path_t *path = malloc(sizeof(Path_t));
	path->sdf = sdfTotal;
	for(int k = 0; k<i;k++){
		path->route[k] = nodosTotal[k];
	}
	return path;
}
