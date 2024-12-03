//Saideep Ambari
//1227110055
#include <iostream>
#include "stack.h"
#include "graph.h"
#include <cstdio>
#include <cfloat>
using namespace std;

pGRAPH createGraph(int n,int m) {
    pGRAPH graphInstance = new GRAPH;
    graphInstance->n = n;
    graphInstance->m = m;
    graphInstance->V = new pVERTEX[n+1];
    graphInstance->ADJ = new pNODE[n+1];
    for (int i = 1; i <= n; ++i) {
        graphInstance->V[i] = new VERTEX;
        graphInstance->V[i]->index = i;
        graphInstance->V[i]->key = DBL_MAX;
        graphInstance->V[i]->parentIndex = -1;
        graphInstance->ADJ[i] = nullptr;
    }
    return graphInstance;
}

void addEdge(pGRAPH graphInstance,int edgeID,int u,int v,double w,bool directed,bool flag) {
    pNODE node = new NODE;
    node->index = edgeID;
    node->u = u;
    node->v = v;
    node->w = w;
    node->next = nullptr;
    if (flag) {
        if (graphInstance->ADJ[u] == nullptr) {
            graphInstance->ADJ[u] = node;
        }
		else {
            pNODE tmp = graphInstance->ADJ[u];
            while (tmp->next) tmp = tmp->next;
            tmp->next = node;
        }
    }
	else {
        node->next = graphInstance->ADJ[u];
        graphInstance->ADJ[u] = node;
    }
    if (!directed) {
        addEdge(graphInstance,edgeID,v,u,w,true,flag);
    }
}

void printAdjList(pGRAPH graphInstance) {
    for(int i = 1; i <= graphInstance->n; ++i) {
        cout << "ADJ[" << i << "]:";
        for(pNODE node = graphInstance->ADJ[i]; node != nullptr; node = node->next)
            printf("-->[%d %d: %4.2lf]",node->u,node->v,node->w);
        cout << endl;
    }
}

void initSingleSource(pGRAPH graphInstance,int src) {
    for(int i = 1; i <= graphInstance->n; ++i) {
        graphInstance->V[i]->key = DBL_MAX;
        graphInstance->V[i]->parentIndex = -1;
    }
    graphInstance->V[src]->key = 0.0;
}

void relax(pGRAPH graphInstance,pHEAP heap,int u,int v,double w) {
    if (graphInstance->V[v]->key > graphInstance->V[u]->key + w) {
        graphInstance->V[v]->key = graphInstance->V[u]->key + w;
        graphInstance->V[v]->parentIndex = u;
        decreaseKey(heap,graphInstance->V[v]->pos,graphInstance->V[v]->key);
    }
}



void singleSource(pGRAPH graphInstance,int src) {
    initSingleSource(graphInstance,src);
    pHEAP heap = createHeap(graphInstance->n);
    for (int i = 1; i <= graphInstance->n; ++i) {
        insert(heap,graphInstance->V[i]);
    }
    while (heap->size) {
        pVERTEX u = extractMin(heap);
        for (pNODE node = graphInstance->ADJ[u->index]; node != nullptr; node = node->next) {
            relax(graphInstance,heap,u->index,node->v,node->w);
        }
    }
    deleteHeap(heap);
}





void deleteGraph(pGRAPH graphInstance) {
    for (int i = 1; i <= graphInstance->n; ++i) {
        delete graphInstance->V[i];
        pNODE node = graphInstance->ADJ[i];
        while (node) {
            pNODE temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] graphInstance->ADJ;
    delete[] graphInstance->V;
    delete graphInstance;
}




void singlePair(pGRAPH graphInstance,int src,int dest) {
    initSingleSource(graphInstance,src);
    pHEAP heap = createHeap(graphInstance->n);
    for(int i = 1; i <= graphInstance->n; ++i) {
        insert(heap,graphInstance->V[i]);
    }
    while(heap->size > 0) {
        pVERTEX u = extractMin(heap);

        if (u->index == dest && u->key != DBL_MAX) {
            break;
        }
        if (u->key == DBL_MAX) {
            break;
        }

        for (pNODE node = graphInstance->ADJ[u->index]; node != nullptr; node = node->next) {
            int v = node->v;
            double weight = node->w;
            if (u->key != DBL_MAX && ( u->index == src || graphInstance->V[u->index]->parentIndex != -1)) {
                relax(graphInstance,heap,u->index,v,weight);
            }
        }
    }
    deleteHeap(heap);
}
