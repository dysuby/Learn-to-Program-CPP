 #ifndef RHTREE_HPP
#define RHTREE_HPP
#include <iostream>
typedef struct tree {
  int data;
  tree* right;
  tree* left;
  tree(int _data = 0, tree* _right = NULL, tree* _left = NULL): data(_data),
      right(_right), left(_left) {}
} tree;
class RHTree {
  private:
    tree* root;
  public:
    RHTree(): root(NULL) {}
    ~RHTree();
    void insert(int x);
    void inOrder(tree* root);
    void preOrder(tree* root);
    void postOrder(tree* root);
    tree* getRoot() {
      return root;
    }
    void clear(tree* root);
};
#endif