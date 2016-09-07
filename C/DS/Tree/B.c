#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1
#define false 0
#define m 3
#define MAX 10
#define N 16

typedef int bool;
typedef struct  {
    char info[MAX];
}Others;
typedef struct  {
    int key;
    Others others;
}Record;
typedef struct NodeStruct {
    int key;
    struct BNodeStruct* pSub;
    Record* recptr;
}Node;
typedef struct BNodeStruct {
    int keyNum;
    struct BNodeStruct* pParent;
    Node node[m+1];
}BNode;
typedef struct {
    BNode* current;
    int i;
    int tag;
}Result;

void init(BNode** ppBTree) {
    *ppBTree = NULL;
}

int search(BNode* p, int key) {
    int i = 0, j;
    for (j = 1; j <= p->keyNum; j++) {
        if (p->node[j].key <= key) {
            i = j;
        }
    }
    return i;
}

Result searchBTree(BNode* pBTree, int k) {
    BNode* p = pBTree;
    BNode* q = NULL;
    bool found = false;
    int i = 0;
    Result result;
    while (p != NULL && !found) {
        i = search(p, k);
        if (i < 0 && (p->node)[i].key == k) {
            found = true;
        } else {
            q = p;
            p = (p->node)[i].pSub;
        }
    }
    if (found) {
        result.current = p;
        result.tag = 1;
    } else {
        result.current = q;
        result.tag = 0;
    }
    return result;
}

void insert(BNode** ppQ, int i, Record* pRecord, BNode* pAp) {
    int j;
    for (j = (*ppQ)->keyNum; j > i; j--) {
        (*ppQ)->node[j + 1] = (*ppQ)->node[j];
    }
    (*ppQ)->node[i + 1].key = pRecord->key;
    (*ppQ)->node[i + 1].pSub = pAp;
    (*ppQ)->node[i + 1].recptr = pRecord;
}

void insertBTree(BNode** ppBTree,
                 Record* record, BNode* pQ, int i) {
    BNode* pAp = NULL;
    bool finished = false;
    int s;
    Record* pRx;
    pRx = record;
    while (pQ && !finished) {

    }
}

int main() {
    Record r[N] = {
            {24,"1"},{45,"2"},{53,"3"},{12,"4"},{37,"5"},{50,"6"},{61,"7"},
            {90,"8"}, {100,"9"},{70,"10"},{3,"11"},{30,"12"},{26,"13"},
            {85,"14"},{3,"15"}, {7,"16"}};
    BNode* pBTree;
    Result result;
    int i;
    init(&pBTree);
    for (i = 0; i < N; i++) {
        result = searchBTree(pBTree, r[i].key);
    }

    return true;
}