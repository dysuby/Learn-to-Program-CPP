 #include "TreeNode.h"
#include <stdlib.h>
#define SETNULL(X) X -> left = NULL; \
                  X -> right = NULL;

int findPos(int num, int in[], int size) {
  for (int index = 0; index < size; ++index)
    if (in[index] == num)
      return index;
}

TreeNode* reConstructBinaryTree(int pre[], int in[], int size) {
  if (size == 0)
    return NULL;
  TreeNode *root = malloc(sizeof(TreeNode));
  root -> val = pre[0];
  SETNULL(root);
  TreeNode *temp = root;
  for (int index = 1; index < size; ++index) {
    while (1) {
      int parent = findPos(temp -> val, in, size);
      int son = findPos(pre[index], in, size);
      if (son < parent) {
        if (temp -> left) {
          temp = temp -> left;
        }
        else {
          temp -> left = malloc(sizeof(TreeNode));
          temp -> left -> val = pre[index];
          SETNULL(temp -> left);
          temp = root;
          break;
        }  
      } else {
        if (temp -> right) {
          temp = temp -> right;
        }
        else {
          temp -> right = malloc(sizeof(TreeNode));
          temp -> right -> val = pre[index];
          SETNULL(temp -> right);
          temp = root;
          break;
        }  
      }
    }
  }
  return root;
}

void deleteTree(TreeNode* root) {
  if (root) {
    deleteTree(root -> left);
    deleteTree(root -> right);
    free(root);
  }
}