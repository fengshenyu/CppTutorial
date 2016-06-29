#include <stdio.h>
#include <malloc.h>
#include <limits.h>

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

void initMinIndex(HuffmanTree* pHuffmanTree, int minIndex[], int index) {
    int count = 0;
    for (int i = 0; i < index; i++) {
        HuffmanNode* p = pHuffmanTree->pHuffmanNode + i;
        if (p->parent == 0) {
            minIndex[count++] = i;
        }
        if (count == 2) {
            break;
        }
    }
}

void updateMin(HuffmanTree* pHuffmanTree, int minIndex[], int index) {
    initMinIndex(pHuffmanTree, minIndex, index);
    for (int i = minIndex[1] + 1; i < index; i++) {
        HuffmanNode* p = pHuffmanTree->pHuffmanNode + i;
        if (p->parent == 0) {
            if (p->weight < (p + minIndex[0])->weight) {
                minIndex[0] = i;
                continue;
            }
            if (p->weight < (p + minIndex[1])->weight) {
                minIndex[1] = i;
            }
        }
    }
}

void createHuffmanTree(HuffmanTree* pHuffmanTree) {
    for (int i = pHuffmanTree->init; 
            i < pHuffmanTree->total; i++) {
        int minIndex[2];
        updateMin(pHuffmanTree, minIndex, i);
        HuffmanNode* p = pHuffmanTree->pHuffmanNode;
        (p + minIndex[0])->parent = i;
        (p + minIndex[1])->parent = i;
        (p + i)->lChild = minIndex[0];
        (p + i)->rChild = minIndex[1];
        (p + i)->weight = (p + minIndex[0])->weight +
            (p + minIndex[1])->weight;
        if (i == pHuffmanTree->init) {
            printHuffmanTree(pHuffmanTree);
            printf("min1=%d,min2=%d\n", minIndex[0], minIndex[1]);
        }
    }
}

int main() {
    int weightArr[] = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree huffmanTree;
    initHuffmanTree(&huffmanTree, weightArr);
    initWeight(&huffmanTree, weightArr);
    createHuffmanTree(&huffmanTree);
    // printHuffmanTree(&huffmanTree);
    return 0;
}