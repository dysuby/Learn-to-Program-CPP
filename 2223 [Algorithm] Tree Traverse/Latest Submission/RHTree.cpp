#include "RHTree.hpp"
using std::cout;
using std::endl;
void RHTree::insert(int x) {
  if (!root) {
    root = new tree(x);
  }
  else {
    tree* poi = root;
    tree* father = root;
    while (poi) {
      father = poi;
      if (x > poi -> data)
        poi = poi -> right;
      else if (x <= poi -> data)
        poi = poi -> left;
    }
    poi = new tree(x);
    x <= father -> data ? father -> left = poi : father -> right = poi;
  }
}
RHTree::~RHTree() {
  clear(root);
  root = NULL;
}
void RHTree::clear(tree* root) {
  if (root) {
    clear(root -> left);
    clear(root -> right);
    delete root;
  }
}
void RHTree::inOrder(tree* root) {
  if (root) {
    inOrder(root -> left);
    cout << " " << root -> data;
    inOrder(root -> right);
  }
}
void RHTree::preOrder(tree* root) {
  if (root) {
    cout << " " << root -> data;
    preOrder(root -> left);
    preOrder(root -> right);
  }
}
void RHTree::postOrder(tree* root) {
  if (root) {
    postOrder(root -> left);
    postOrder(root -> right);
    cout << " " << root -> data;
  }
}