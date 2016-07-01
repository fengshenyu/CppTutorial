#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef struct {
    int weight;
    int parent, lChild, rChild;
}HuffmanNode;
typedef struct {
    HuffmanNode* pHuffmanNode;
    int init;
    int total;
}HuffmanTree;
typedef struct {
    int index;
    int weight;
}Pair;

void printHuffmanTree(HuffmanTree* pHuffmanTree) {
    for (int i = 0; i < pHuffmanTree->total; i++) {
        HuffmanNode* p = pHuffmanTree->pHuffmanNode + i;
        printf("index=%d,weight=%d,parent=%d,lChild=%d,rChild=%d\n",
            i, p->weight, p->parent, p->lChild, p->rChild);
    }
}

void initHuffmanTree(HuffmanTree* pHuffmanTree, int weightArr[]) {
    int n = 8;
    pHuffmanTree->pHuffmanNode = (HuffmanNode*)malloc((2 * n - 1) * sizeof(HuffmanNode));
    pHuffmanTree->init = n;
    pHuffmanTree->total = 2 * n - 1;
}

void initWeight(HuffmanTree* pHuffmanTree, int weightArr[]) {
    for (int i = 0; i < pHuffmanTree->total; i++) {
        if (i < pHuffmanTree->init) {
            (pHuffmanTree->pHuffmanNode + i)->weight = weightArr[i];
        }
        (pHuffmanTree->pHuffmanNode + i)->parent = 0;
        (pHuffmanTree->pHuffmanNode + i)->lChild = 0;
        (pHuffmanTree->pHuffmanNode + i)->rChild = 0;
    }
}

void initMinIndex(HuffmanTree* pHuffmanTree, Pair indexWeight[], int index) {
    int count = 0;
    for (int i = 0; i < index; i++) {
        HuffmanNode* p = pHuffmanTree->pHuffmanNode + i;
        if (p->parent != 0) {
            continue;
        }
        if (count == 0) {
            indexWeight[0].index = i;
            indexWeight[0].weight = p->weight;
            count = 1;
        } else {
            if (p->weight < indexWeight[0].weight) {
                indexWeight[1].index = indexWeight[0].index;
                indexWeight[1].weight = indexWeight[0].weight;
                indexWeight[0].index = i;
                indexWeight[0].weight = p->weight;
            } else {
                indexWeight[1].index = i;
                indexWeight[1].weight = p->weight;
            }
            break;
        }
        
    }
}

void updateMin(HuffmanTree* pHuffmanTree, Pair indexWeight[], int index) {
    initMinIndex(pHuffmanTree, indexWeight, index);
    int i = indexWeight[0].index > indexWeight[1].index ? indexWeight[0].index :
            indexWeight[1].index;
    for (i = i + 1; i < index; i++) {
        HuffmanNode* pStart = pHuffmanTree->pHuffmanNode;
        HuffmanNode* pIndex = pStart + i;
        if (pIndex->parent != 0) {
            continue;
        }
        if (pIndex->weight < (pStart + indexWeight[1].index)->weight) { 
            if (pIndex->weight > (pStart + indexWeight[0].index)->weight) {
                indexWeight[1].index = i;
                indexWeight[1].weight = pIndex->weight;
            } else {
                indexWeight[1].index = indexWeight[0].index;
                indexWeight[1].weight = indexWeight[0].weight;
                indexWeight[0].index = i;
                indexWeight[0].weight = pIndex->weight;
            }
        }
    }
}

void createHuffmanTree(HuffmanTree* pHuffmanTree) {
    for (int i = pHuffmanTree->init; 
            i < pHuffmanTree->total; i++) {
        Pair indexWeight[2];
        updateMin(pHuffmanTree, indexWeight, i);
        HuffmanNode* p = pHuffmanTree->pHuffmanNode;
        (p + indexWeight[0].index)->parent = i;
        (p + indexWeight[1].index)->parent = i;
        (p + i)->lChild = indexWeight[0].index;
        (p + i)->rChild = indexWeight[1].index;
        (p + i)->weight = (p + indexWeight[0].index)->weight +
            (p + indexWeight[1].index)->weight;
    }
}

int main() {
    int weightArr[] = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree huffmanTree;
    initHuffmanTree(&huffmanTree, weightArr);
    initWeight(&huffmanTree, weightArr);
    createHuffmanTree(&huffmanTree);
    printHuffmanTree(&huffmanTree);
    return 0;
}