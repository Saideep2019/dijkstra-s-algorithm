#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

struct STACK {
	int id;
    int top;
    int capacity;
    pVERTEX* array;
};

typedef STACK* pSTACK;

pSTACK initializeStack(int capacity);
bool isStackEmpty(pSTACK stack);
bool isStackFull(pSTACK stack);
void push(pSTACK stack, pVERTEX vertex);
pVERTEX pop(pSTACK stack);
pVERTEX peek(pSTACK stack);
void freeStack(pSTACK stack);
void printStack(pSTACK stack);

#endif // STACK_H
