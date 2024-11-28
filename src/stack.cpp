#include "stack.h"
#include <iostream>
#include <cfloat>
using namespace std;

pSTACK createStack() {
    return nullptr;
}

void push(pSTACK* stack,pVERTEX vertex) {
    pSTACK node = new STACK;
    node->vertex = vertex;
    node->next = *stack;
    *stack = node;
}

pVERTEX pop(pSTACK* stack) {
    if (*stack == nullptr) return nullptr;
    pSTACK tmp = *stack;
    pVERTEX vertex = tmp->vertex;
    *stack = (*stack)->next;
    delete tmp;
    return vertex;
}

void deleteStack(pSTACK* stack) {
    while (*stack) {
        pop(stack);
    }
}

void printPath(pGRAPH graph, int src, int dest) {
    // Check if there is no path to the destination
    if (graph->V[dest]->key == DBL_MAX || graph->V[dest]->parentIndex == -1) {
        cout << "There is no path from " << src << " to " << dest << "." << endl;
        return;
    }

    // Use a stack to reconstruct the path
    pSTACK pathStack = nullptr;
    int curr = dest;
    while (curr != -1) {
        push(&pathStack, graph->V[curr]);
        curr = graph->V[curr]->parentIndex;
    }

    // Print the path header
    printf("The shortest path from %d to %d is: ", src, dest);

    // Print the path with weights
    while (pathStack != nullptr) {
        pVERTEX v = pop(&pathStack);
        printf("[%d:%8.2lf]", v->index, v->key);
        if (pathStack != nullptr) {
            printf("-->");
        }
    }

    // Add the required period at the end of the output
    cout << "." << endl;

    // Clean up the stack
    deleteStack(&pathStack);
}
