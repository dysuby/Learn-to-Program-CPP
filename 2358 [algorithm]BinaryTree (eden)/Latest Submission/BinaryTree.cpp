#include "BinaryTree.hpp"
#include <algorithm>
using std::vector;
using std::queue;
using std::find;
typedef BinaryTree::Node Node;

BinaryTree::BinaryTree(const BinaryTree& tar) {
  if (tar.root == NULL) {
    root = NULL;
  }
  else {
    root = new Node(tar.root -> val);
    copyNode(tar.root, root);    
  }
}

BinaryTree::BinaryTree(std::vector<char>& vec) {
  if (!vec.size()) {
    root = NULL;
    return;
  }
  auto i = vec.begin();
  root = new Node(*i);
  queue<Node*> tree;
  tree.push(root);
  Node* father = root;
  ++i;
  bool flag = true;
  while (tree.size() && root -> val != EMPTY_ELE && i != vec.end()) {
    father = tree.front();
    Node* son = new Node(*i);
    if (father -> left || !flag) {
      if (*i != EMPTY_ELE) 
        father -> right = son;
      tree.pop();
      flag = true;
    } else if (flag) {
      if (*i == EMPTY_ELE) 
        flag = false;
      else
        father -> left = son;
    }
    if(*i != EMPTY_ELE)
      tree.push(son);
    else
      delete son;
    ++i;
  }
  // auto fun = [](Node* i) -> void {if (i -> left && i -> left -> val == EMPTY_ELE) {
  //                                   delete i -> left;
  //                                   i -> left = NULL;
  //                                 }
  //                                 if (i -> right && i -> right -> val == EMPTY_ELE) {
  //                                   delete i -> right;
  //                                   i -> right = NULL;
  //                                 }};
  // preOrder(fun, root);
}
        // created by preorder and inorder

bool isLeft(vector<char> range, char val, char i) {
  auto pos = find(range.begin(), range.end(), val);
  auto father = find(range.begin(), range.end(), i);
  return pos < father;
}

BinaryTree::BinaryTree(const std::vector<char>& preOrder,
                      const std::vector<char>& inOrder) {
  if (!preOrder.size()) {
    root = NULL;
    return;
  }
  root = new Node(preOrder.front());
  Node* node = root;
  Node* prev = root;
  for (auto i = preOrder.begin() + 1; i < preOrder.end(); ++i) {
    while (node) {
      prev = node;
      if (isLeft(inOrder, *i, node -> val))
        node = prev -> left;
      else
        node = prev -> right;
    }
    if (isLeft(inOrder, *i, prev -> val))
      prev -> left = new Node(*i);
    else
      prev -> right = new Node(*i);
    node = root;
  }
}

BinaryTree::~BinaryTree() {
  clear();
}

BinaryTree& BinaryTree::operator=(const BinaryTree& tar) {
  if (root == tar.root)
    return *this;
  clear();
  root = new Node(tar.root -> val);
  copyNode(tar.root, root);
  return *this;
}

Node* BinaryTree::getRoot() const {
  return root;
}

void BinaryTree::clear() {
  postOrder([](BinaryTree::Node* i) -> void {delete i;}, root);
  root = NULL;
}

void BinaryTree::preOrder(void (*visite)(Node*), Node* node) {
  if (node) {
    visite(node);
    preOrder(visite, node -> left);
    preOrder(visite, node -> right);
  }
}

void BinaryTree::inOrder(void (*visite)(Node*), Node* node) {
  if (node) {
    inOrder(visite, node -> left);
    visite(node);
    inOrder(visite, node -> right);
  }
}

void BinaryTree::postOrder(void (*visite)(Node*), Node* node) {
  if (node) {
    postOrder(visite, node -> left);
    postOrder(visite, node -> right);
    visite(node);
  } 
}

Node * BinaryTree::copyNode(Node * oldNode, Node * newNode) {
  if (oldNode) {
    if (oldNode -> left) {
      newNode -> left = new Node(oldNode -> left -> val);
    }
    if (oldNode -> right) {
      newNode -> right = new Node(oldNode -> right -> val);
    }
    copyNode(oldNode ->left, newNode -> left);
    copyNode(oldNode -> right, newNode -> right);
    return 0;
  } else {
    return 0;
  }
}