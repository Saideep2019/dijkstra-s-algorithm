#include <iostream>
#include "stack.h"
#include "graph.h"
#include <cstdio>
#include <cfloat>
using namespace std;

pGRAPH createGraph(int n,int m) {
    pGRAPH graph = new GRAPH;
    graph->n = n;
    graph->m = m;
    graph->V = new pVERTEX[n+1];
    graph->ADJ = new pNODE[n+1];
    for (int i = 1; i <= n; ++i) {
        graph->V[i] = new VERTEX;
        graph->V[i]->index = i;
        graph->V[i]->key = DBL_MAX;
        graph->V[i]->parentIndex = -1;
        graph->ADJ[i] = nullptr;
    }
    return graph;
}

void addEdge(pGRAPH graph,int edgeindex,int u,int v,double w,bool directed,bool flag) {
    pNODE node = new NODE;
    node->index = edgeindex;
    node->u = u;
    node->v = v;
    node->w = w;
    node->next = nullptr;
    if (flag) {
        if (graph->ADJ[u] == nullptr) {
            graph->ADJ[u] = node;
        }
		else {
            pNODE tmp = graph->ADJ[u];
            while (tmp->next) tmp = tmp->next;
            tmp->next = node;
        }
    }
	else {
        node->next = graph->ADJ[u];
        graph->ADJ[u] = node;
    }
    if (!directed) {
        addEdge(graph,edgeindex,v,u,w,true,flag);
    }
}

void printAdjList(pGRAPH graph) {
    for(int i = 1; i <= graph->n; ++i) {
        cout << "ADJ[" << i << "]:";
        for(pNODE node = graph->ADJ[i]; node != nullptr; node = node->next)
            printf("-->[%d %d: %4.2lf]",node->u,node->v,node->w);
        cout << endl;
    }
}

void initSingleSource(pGRAPH graph,int src) {
    for(int i = 1; i <= graph->n; ++i) {
        graph->V[i]->key = DBL_MAX;
        graph->V[i]->parentIndex = -1;
    }
    graph->V[src]->key = 0.0;
}

void relax(pGRAPH graph,pHEAP heap,int u,int v,double w) {
    if (graph->V[v]->key > graph->V[u]->key + w) {
        graph->V[v]->key = graph->V[u]->key + w;
        graph->V[v]->parentIndex = u;
        decreaseKey(heap,graph->V[v]->pos,graph->V[v]->key);
    }
}

void singlePairShortestPath(pGRAPH graph,int src,int dest) {
    initSingleSource(graph,src);
    pHEAP heap = createHeap(graph->n);
    for(int i = 1; i <= graph->n; ++i) {
        insert(heap,graph->V[i]);
    }
    while(heap->size > 0) {
        pVERTEX u = extractMin(heap);

        if (u->index == dest && u->key != DBL_MAX) {
            break;
        }
        if (u->key == DBL_MAX) {
            break;
        }

        for (pNODE node = graph->ADJ[u->index]; node != nullptr; node = node->next) {
            int v = node->v;
            double weight = node->w;
            if (u->key != DBL_MAX && ( u->index == src || graph->V[u->index]->parentIndex != -1)) {
                relax(graph,heap,u->index,v,weight);
            }
        }
    }
    deleteHeap(heap);
}

void singleSourceShortestPath(pGRAPH graph,int src) {
    initSingleSource(graph,src);
    pHEAP heap = createHeap(graph->n);
    for (int i = 1; i <= graph->n; ++i) {
        insert(heap,graph->V[i]);
    }
    while (heap->size) {
        pVERTEX u = extractMin(heap);
        for (pNODE node = graph->ADJ[u->index]; node != nullptr; node = node->next) {
            relax(graph,heap,u->index,node->v,node->w);
        }
    }
    deleteHeap(heap);
}

void deleteGraph(pGRAPH graph) {
    for (int i = 1; i <= graph->n; ++i) {
        delete graph->V[i];
        pNODE node = graph->ADJ[i];
        while (node) {
            pNODE temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] graph->ADJ;
    delete[] graph->V;
    delete graph;
}
