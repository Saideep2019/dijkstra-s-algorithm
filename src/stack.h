//Saideep Ambari
//1227110055
#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

pSTACK createStack();
void push(pSTACK *stack, pVERTEX vertex);
pVERTEX pop(pSTACK *stack);
void freeStack(pSTACK *stack);
void showPath(pGRAPH graph, int src, int dest);

#endif
