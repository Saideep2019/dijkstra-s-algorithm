#include "stack.h"
#include <cstdlib>
#include <iostream>

pSTACK initializeStack(int capacity) {
    pSTACK stack = new STACK;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new pVERTEX[capacity];
    return stack;
}

bool isStackEmpty(pSTACK stack) {
    return stack->top == -1;
}

bool isStackFull(pSTACK stack) {
    return stack->top == stack->capacity - 1;
}

void push(pSTACK stack, pVERTEX vertex) {
    if (isStackFull(stack)) {
        std::cerr << "Stack overflow\n";
        return;
    }
    stack->array[++stack->top] = vertex;
}

pVERTEX pop(pSTACK stack) {
    if (isStackEmpty(stack)) {
        std::cerr << "Stack underflow\n";
        return nullptr;
    }
    return stack->array[stack->top--];
}

pVERTEX peek(pSTACK stack) {
    if (isStackEmpty(stack)) {
        std::cerr << "Stack is empty\n";
        return nullptr;
    }
    return stack->array[stack->top];
}

void freeStack(pSTACK stack) {
    delete[] stack->array;
    delete stack;
}

void printStack(pSTACK stack) {
    if (isStackEmpty(stack)) {
        std::cout << "Stack is empty\n";
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        std::cout << stack->array[i]->index << " ";
    }
    std::cout << "\n";
}
