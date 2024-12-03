//Saideep Ambari
//1227110055
#include "stack.h"
#include <iostream>
#include <cfloat>
using namespace std;

pSTACK createStack() {
    return nullptr;
}

void push(pSTACK* stackInitialization,pVERTEX vertex) {
    pSTACK node = new STACK;
    node->vertex = vertex;
    node->next = *stackInitialization;
    *stackInitialization = node;
}

pVERTEX pop(pSTACK* stackInitialization) {
    if (*stackInitialization == nullptr) return nullptr;
    pSTACK tmp = *stackInitialization;
    pVERTEX vertex = tmp->vertex;
    *stackInitialization = (*stackInitialization)->next;
    delete tmp;
    return vertex;
}

void deleteStack(pSTACK* stackInitialization) {
    while (*stackInitialization) {
        pop(stackInitialization);
    }
}

void printPath(pGRAPH graphInitialization,int src,int dest) {
    if (graphInitialization->V[dest]->key == DBL_MAX || graphInitialization->V[dest]->parentIndex == -1) {
        cout << "There is no path from " <<
         src << " to " << dest << "." << endl;
        return;
    }
    pSTACK pathStack = nullptr;
    int curr = dest;
    while (curr != -1) {
        push(&pathStack,graphInitialization->V[curr]);
        curr = graphInitialization->V[curr]->parentIndex;
    }
    printf("The shortest path from %d to %d is:\n",src,dest);
    while (pathStack != nullptr) {
        pVERTEX v = pop(&pathStack);
        printf("[%d:%8.2lf]",v->index,v->key);
        if (pathStack != nullptr) {
            printf("-->");
        }
    }
    cout << "." << endl;
    deleteStack(&pathStack);
}
