#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1
#define false 0
#define MAX_SIZE 50
#define LeftHigh 1
#define EqualHigh 0
#define RightHigh -1

typedef int bool;
typedef struct {
    int key;
    char* name;
}EleType;
typedef struct BalanceBinaryStruct{
    EleType data;
    int balance;
    struct BalanceBinaryStruct* lChild;
    struct BalanceBinaryStruct* rChild;
}BalanceBinary;

void rightRotate(BalanceBinary** currentRoot) {
    BalanceBinary* leftChild = (*currentRoot)->lChild;
    (*currentRoot)->lChild = leftChild->rChild;
    leftChild->rChild = *currentRoot;
    *currentRoot = leftChild;
}

void leftRotate(BalanceBinary** currentRoot) {
    BalanceBinary* rightChild = (*currentRoot)->rChild;
    (*currentRoot)->rChild = rightChild->lChild;
    rightChild->lChild = *currentRoot;
    *currentRoot = rightChild;
}

void leftBalance(BalanceBinary** root) {
    BalanceBinary* lChild =  (*root)->lChild;
    switch (lChild->balance) {
        
    }
}

void insertAVL(BalanceBinary** root, EleType eleType, bool* taller) {
    if (*root == NULL) {
        *root = (BalanceBinary*)malloc(sizeof(BalanceBinary));
        (*root)->lChild = NULL;
        (*root)->rChild = NULL;
        (*root)->data = eleType;
        (*root)->balance = EqualHigh;
        *taller = true;
    } else {
        if (eleType.data == ((*root)->data).key) {
            *taller = false;
            return false;
        }
        if (eleType.data < ((*root)->data).key) {
            if (!insertAVL((*root)->lChild, eleType, taller)) {
                return false;
            }
            if (*taller) {
                switch ((*root)->balance) {
                    case LeftHigh:
                        leftBalance(root);
                        *taller = false;
                        break;
                    case EqualHigh:
                        (*root)->balance = LeftHigh;
                        *taller = true;
                        break;
                    case RightHigh:
                        (*root)->balance = EqualHigh;
                        *taller = false;
                        break;
                }
            }
        } else {
            if (!insertAVL((*root)->rChild, eleType, taller)) {
                return false;
            }
            if (*taller) {
                switch ((*root)->balance) {
                    case LeftHigh:
                        (*root)->balance = EqualHigh;
                        *taller = false;
                        break;
                    case EqualHigh:
                        (*root)->balance = RightHigh;
                        *taller = true;
                        break;
                    case RightHigh:
                        rightBalance(root);
                        *taller = false;
                        break;
                }
            }
        }
    }
    return true;
}

int main() {

}