#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct TAG_VERTEX {
    int index;
    int parentIndex;
    int pos;
    double key;
    int pi;
}
VERTEX;
typedef VERTEX *pVERTEX;
typedef VERTEX ELEMENT;
typedef VERTEX *pELEMENT;
typedef ELEMENT *pELEMENT;

typedef struct TAG_NODE {
    int index;
    int u;
    int v;
    double w;
    struct TAG_NODE* next;
}
NODE;
typedef NODE* pNODE;

typedef struct TAG_HEAP {
    int size;
    int capacity;
    pELEMENT* H;
}
HEAP;
typedef HEAP* pHEAP;

typedef struct TAG_GRAPH {
    int n;
    int m;
    pVERTEX* V;
    pNODE* ADJ;
}
GRAPH;
typedef GRAPH* pGRAPH;

typedef struct TAG_STACK {
    pVERTEX vertex;
    struct TAG_STACK* next;
}
STACK;
typedef STACK* pSTACK;



// Element structure for representing a heap element
struct Element {
    int index;       // Index of the element
    double value;    // Key value associated with the element
    int position;    // Position in the heap

    // Constructor with default values
    Element(int idx = 0, double val = 0.0, int pos = 0)
        : index(idx), value(val), position(pos) {}
};

// Heap structure for managing the heap data
struct Heap {
    int maxCapacity;     // Maximum capacity of the heap
    int currentSize;     // Current size of the heap
    int* heapArray;      // Array to store heap element indices
    Element** elementArray; // Array to store Element pointers

    // Constructor for initializing the heap
    Heap(int maxCap)
        : maxCapacity(maxCap), currentSize(0) {
        heapArray = new int[maxCapacity + 1];
        elementArray = new Element*[maxCapacity + 1];
    }

    // Destructor for cleaning up allocated memory
    ~Heap() {
        delete[] heapArray;
        for (int i = 0; i < maxCapacity; ++i) {
            delete elementArray[i];
        }
        delete[] elementArray;
    }
};

#endif
