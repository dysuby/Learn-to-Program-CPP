#ifndef TREE_H
#define TREE_H
#define SET_NULL(X) (X) -> left = NULL; \
                    (X) -> right = NULL;
#include <stdio.h>

typedef struct node {
  int x;
  struct node* left;
  struct node* right;
} BN;

void buildTree(BN **root) {
  int num[31] = {0};
  int index = 0;
  while (1) {
    scanf("%d", &num[index]);
    if (num[index] != -1)
      ++index;
    else
      break;
  }
  if (index == 0) {
    *root = NULL;
    return;
  }
  *root = (BN*)malloc(sizeof(BN));
  (*root) -> x = num[0];
  SET_NULL(*root);
  int head = 0;
  int tail = 1;
  BN *que[100] = {*root};
  index = 1;
  while (num[index] != -1) {
    BN *temp = que[head];
    if (temp -> left) {
      que[tail] = temp -> left;
      ++tail;
      if (temp -> right) {
        que[tail] = temp -> right;
        ++tail;
        ++head;
      } else {
        temp -> right = (BN*)malloc(sizeof(BN));
        SET_NULL(temp -> right);
        temp -> right -> x = num[index];
        ++index;
      }
    } else {
      temp -> left = (BN*)malloc(sizeof(BN));
      SET_NULL(temp -> left);
      temp -> left -> x = num[index];
      ++index;
    }
  }
}

void outputTree(BN *root) {
  if (root) {
    outputTree(root -> left);
    printf("%d ", root -> x);
    outputTree(root -> right);  
  }
}
#endif