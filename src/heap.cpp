#include "heap.h"
#include <cstdlib>
#include <algorithm>

pHEAP InitializeHeap(int capacity) {
    pHEAP heap = new HEAP;
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = new pVERTEX[capacity + 1];
    return heap;
}

void Insert(pHEAP heap, pVERTEX element) {
    if (heap->size >= heap->capacity) {
        // Handle heap overflow
        return;
    }

    heap->size++;
    int i = heap->size;
    heap->H[i] = element;
    element->position = i;

    // Bubble up
    while (i > 1 && heap->H[i]->key < heap->H[i/2]->key) {
        std::swap(heap->H[i], heap->H[i/2]);
        heap->H[i]->position = i;
        heap->H[i/2]->position = i/2;
        i = i/2;
    }
}

pVERTEX ExtractMin(pHEAP heap) {
    if (IsEmpty(heap)) {
        return nullptr;
    }

    pVERTEX min = heap->H[1];
    heap->H[1] = heap->H[heap->size];
    heap->H[1]->position = 1;
    heap->size--;

    MinHeapify(heap, 1);

    return min;
}

void DecreaseKey(pHEAP heap, int index, double newKey) {
    if (newKey > heap->H[index]->key) {
        return;  // New key is greater, do nothing
    }

    heap->H[index]->key = newKey;

    while (index > 1 && heap->H[index]->key < heap->H[index/2]->key) {
        std::swap(heap->H[index], heap->H[index/2]);
        heap->H[index]->position = index;
        heap->H[index/2]->position = index/2;
        index = index/2;
    }
}

void MinHeapify(pHEAP heap, int index) {
    int smallest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= heap->size && heap->H[left]->key < heap->H[smallest]->key) {
        smallest = left;
    }

    if (right <= heap->size && heap->H[right]->key < heap->H[smallest]->key) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(heap->H[index], heap->H[smallest]);
        heap->H[index]->position = index;
        heap->H[smallest]->position = smallest;
        MinHeapify(heap, smallest);
    }
}

bool IsEmpty(pHEAP heap) {
    return heap->size == 0;
}

void DestroyHeap(pHEAP heap) {
    delete[] heap->H;
    delete heap;
}
