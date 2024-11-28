#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

pHEAP createHeap(int capacity);
void insert(pHEAP heap, pELEMENT element);
pELEMENT extractMin(pHEAP heap);
void decreaseKey(pHEAP heap, int index, double newKey);
void deleteHeap(pHEAP heap);

#endif
