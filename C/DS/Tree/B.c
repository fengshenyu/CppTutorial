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
    struct BNodeStruct* pSub;//子树指针
    Record* recptr; //Record指针
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

/**
 *
 * @param ppQ 要添加到哪个结点
 * @param i 要添加到第i和i+1之间的位置
 * @param pRecord 要添加的内容
 * @param pAp
 */
void insert(BNode** ppQ, int i, Record* pRecord, BNode* pAp) {
    int j;
    for (j = (*ppQ)->keyNum; j > i; j--) {
        (*ppQ)->node[j + 1] = (*ppQ)->node[j];
    }
    (*ppQ)->node[i + 1].key = pRecord->key;
    (*ppQ)->node[i + 1].pSub = pAp;
    (*ppQ)->node[i + 1].recptr = pRecord;
    (*ppQ)->keyNum++;
}

/**
 * 将结点q分裂成两个结点,前一半保留,后一半移入新的结点ap
 * @param q
 * @param ap
 */
void split(BNode** q, BNode** ap) {
    int i, s = (m + 1) / 2;
    *ap = (BNode*)malloc(sizeof(BNode));
    (*ap)->node[0].pSub = (*q)->node[s].pSub;
    for (i = s + 1; i <= m; i++) {
        (*ap)->node[i - s] = (*q)->node[i];
        if ((*ap)->node[i - s].pSub) {
            (*ap)->node[i - s].pSub->pParent = *ap;
        }
    }
    (*ap)->keyNum = m - s;
    (*ap)->pParent = (*q)->pParent;
    (*q)->keyNum = s - 1;
}
void insertBTree(BNode** T,
                 Record* r, BNode* q, int i) {
    BNode* ap = NULL;
    bool finished = false;
    int s;
    Record *rx;
    rx = r;
    while (q && !finished) {
        insert(&q, i, rx, ap);
        if (q->keyNum < m) {
            finished = true;
        } else {
            s = (m + 1) / 2;
            rx = q->node[s].recptr;
            split(&q, &ap);
            q = q->pParent;
            if (q) {
                i = search(q, rx->key);
            }
        }
    }
}

void printBTree(BNode* DT) {
    int i;
    if (DT) {
        if (DT->node[0].pSub) {
            printBTree(DT->node[0].pSub);
        }
        for (i = 1; i <= DT->keyNum; i++) {
            printf("%d\n", DT->node[i].recptr->key);
            if (DT->node[i].pSub) {
                printBTree(DT->node[i].pSub);
            }
        }
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
        if (!result.tag) {
            insertBTree(&pBTree, &r[i], result.current, i);
        }
    }
    printBTree(pBTree);
    return true;
}