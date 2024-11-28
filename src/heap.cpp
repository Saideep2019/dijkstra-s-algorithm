#include "heap.h"
#include <iostream>
using namespace std;

void swap(pHEAP heap,int i,int j) {
    pELEMENT temp = heap->H[i];
    heap->H[i] = heap->H[j];
    heap->H[j] = temp;
    heap->H[i]->pos = i;
    heap->H[j]->pos = j;
}

pHEAP createHeap(int capacity) {
    pHEAP heap = new HEAP;
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = new pELEMENT[capacity+1];
    return heap;
}

void heapify(pHEAP heap,int i) {
    int min = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heap->size && heap->H[left]->key < heap->H[min]->key) {
        min = left;
    }
    if (right <= heap->size && heap->H[right]->key < heap->H[min]->key) {
        min = right;
    }
    if (min != i) {
        swap(heap,i,min);
        heapify(heap,min);
    }
}

void insert(pHEAP heap,pELEMENT element) {
    if (heap->size == heap->capacity) {
        cerr << "Error: Heap overflow detected" << endl;
        return;
    }
    heap->size++;
    int i = heap->size;
    heap->H[i] = element;
    element->pos = i;
    while (i > 1 && heap->H[i/2]->key > heap->H[i]->key) {
        swap(heap,i,i / 2);
        i = i / 2;
    }
}

void decreaseKey(pHEAP heap,int pos,double newKey) {
    if (newKey > heap->H[pos]->key) {
        cerr << "Error: New key is bigger than current key" << endl;
        return;
    }
    heap->H[pos]->key = newKey;
    int i = pos;
    while (i > 1 && heap->H[i/2]->key > heap->H[i]->key) {
        swap(heap,i,i / 2);
        i = i / 2;
    }
}

pVERTEX extractMin(pHEAP heap) {
    if (heap->size < 1) {
        cerr << "Error: Heap overflow detected" << endl;
        return nullptr;
    }
    pVERTEX min = heap->H[1];
    heap->H[1] = heap->H[heap->size];
    heap->H[1]->pos = 1;
    heap->size--;
    heapify(heap,1);
    return min;
}

void deleteHeap(pHEAP heap) {
    delete[] heap->H;
    delete heap;
}
