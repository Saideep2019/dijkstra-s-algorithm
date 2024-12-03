//Saideep Ambari
//1227110055
#include "heap.h"
#include <iostream>
using namespace std;

void swap(pHEAP heapInitialization,int i,int j) {
    pELEMENT temp = heapInitialization->H[i];
    heapInitialization->H[i] = heapInitialization->H[j];
    heapInitialization->H[j] = temp;
    heapInitialization->H[i]->pos = i;
    heapInitialization->H[j]->pos = j;
}


void decreaseKey(pHEAP heapInitialization,int pos,double newKey) {
    if (newKey > heapInitialization->H[pos]->key) {
        cerr << "Error: New key is bigger than current key" << endl;
        return;
    }
    heapInitialization->H[pos]->key = newKey;
    int i = pos;
    while (i > 1 && heapInitialization->H[i/2]->key > heapInitialization->H[i]->key) {
        swap(heapInitialization,i,i / 2);
        i = i / 2;
    }
}


pHEAP createHeap(int capacity) {
    pHEAP heap = new HEAP;
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = new pELEMENT[capacity+1];
    return heap;
}



void insert(pHEAP heapInitialization,pELEMENT element) {
    if (heapInitialization->size == heapInitialization->capacity) {
        cerr << "Error: Heap overflow detected" << endl;
        return;
    }
    heapInitialization->size++;
    int i = heapInitialization->size;
    heapInitialization->H[i] = element;
    element->pos = i;
    while (i > 1 && heapInitialization->H[i/2]->key > heapInitialization->H[i]->key) {
        swap(heapInitialization,i,i / 2);
        i = i / 2;
    }
}




void heapify(pHEAP heapInitialization,int i) {
    int min = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heapInitialization->size && heapInitialization->H[left]->key < heapInitialization->H[min]->key) {
        min = left;
    }
    if (right <= heapInitialization->size && heapInitialization->H[right]->key < heapInitialization->H[min]->key) {
        min = right;
    }
    if (min != i) {
        swap(heapInitialization,i,min);
        heapify(heapInitialization,min);
    }
}

pVERTEX extractMin(pHEAP heapInitialization) {
    if (heapInitialization->size < 1) {
        cerr << "Error: Heap overflow detected" << endl;
        return nullptr;
    }
    pVERTEX min = heapInitialization->H[1];
    heapInitialization->H[1] = heapInitialization->H[heapInitialization->size];
    heapInitialization->H[1]->pos = 1;
    heapInitialization->size--;
    heapify(heapInitialization,1);
    return min;
}

void deleteHeap(pHEAP heapInitialization) {
    delete[] heapInitialization->H;
    delete heapInitialization;
}
