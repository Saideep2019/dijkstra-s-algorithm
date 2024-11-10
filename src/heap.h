#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

// The HEAP structure
typedef struct TAG_HEAP {
    int capacity;
    int size;
    pVERTEX *H;  // Changed from pELEMENT *H to pVERTEX *H
} HEAP;

typedef HEAP *pHEAP;

// Function prototypes
pHEAP InitializeHeap(int capacity);
void Insert(pHEAP heap, pVERTEX element);  // Changed pELEMENT to pVERTEX
pVERTEX ExtractMin(pHEAP heap);  // Changed return type to pVERTEX
void DecreaseKey(pHEAP heap, int index, double newKey);
void MinHeapify(pHEAP heap, int index);
bool IsEmpty(pHEAP heap);
void DestroyHeap(pHEAP heap);

#endif // HEAP_H
