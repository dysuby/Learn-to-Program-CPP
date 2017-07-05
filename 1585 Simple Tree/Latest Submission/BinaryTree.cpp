#include "BinaryTree.hpp"
#include <iostream>
void BinaryTree::MemoryDelete(node* p) {
  if (p != NULL) {
    MemoryDelete(p -> left);
    MemoryDelete(p -> right);
    delete p;
  }
}  // 内存处理的辅助函数
void BinaryTree::BuildTree(const node* Source_Root, node* &Target_Root) {
  if (Source_Root) {
    if (Source_Root -> left) {
      Target_Root -> left = new node(Source_Root -> left -> ele);
    }
    if (Source_Root -> right) {
      Target_Root -> right = new node(Source_Root -> right -> ele);
    }
    BuildTree(Source_Root ->left, Target_Root -> left);
    BuildTree(Source_Root -> right, Target_Root -> right);
  }
}  // 拷贝构造函数的辅助函数
void BinaryTree::BuildTree(const int* arr, int len, node* &root) {

}  // 数组构建树的辅助函数
void BinaryTree::preorder(const node* p) {
  if (p) {
    std::cout << p -> ele << " ";
    preorder(p -> left);
    preorder(p -> right);
  }
}
BinaryTree::BinaryTree() {
  root = NULL;
}
BinaryTree::BinaryTree(const BinaryTree& source) {
  if (source.root) {
    root = new node(source.root -> ele);
    BuildTree(source.root, root);
  } else {
    root = NULL;
  }
}
BinaryTree::BinaryTree(const int* arr, int len) {
  root = new node(arr[0]);
  for (int index = 1; index < len; ++index) {
    insert(arr[index]);
  }
}
void BinaryTree::ResetTree(const int* arr, int len) {
  clear();
  root = new node(arr[0]);
  for (int index = 1; index < len; ++index) {
    insert(arr[index]);
  }
}  // 清空当前树并重置
BinaryTree::~BinaryTree() {
  clear();
}
void BinaryTree::clear() {
  MemoryDelete(root);
  root = NULL;
}  // 清空
void BinaryTree::insert(int ele) {
  if (root == NULL) {
    root = new node(ele);
    return;
  }
  node *ptr = root;
  node *newnode = new node(ele);
  node *father = root;
  while (ptr) {
    father = ptr;
    if (ele > ptr -> ele) {
      ptr = ptr -> right;
    } else if (ele < ptr -> ele){
      ptr = ptr -> left;
    } else {
      break;
    }
  }
  if (ptr && ele == ptr -> ele) {
    delete newnode;
    return;
  } else if (ele > father -> ele) {
    father -> right = newnode;
  } else {
    father -> left = newnode;
  }
}  // 按值插入
void BinaryTree::Delete(int ele) {
  node *ptr = root;
  node *father = ptr;
  while (ptr && ptr -> ele != ele) {
    father = ptr;
    if (ptr -> ele > ele) {
      ptr = ptr -> left;
    } else {
      ptr = ptr -> right;
    }
  }
  if (root == ptr && root && root -> ele == ele) {
    if (root -> left == NULL) {
      root = root -> right;
      delete ptr;
    } else {
      node *child = root -> left;
      node *cfather = root;
      while (child -> right) {
        cfather = child;
        child = child -> right;
      }
      root -> ele = child -> ele;
      if (root == cfather) {
        root -> left = child -> left;
      } else {
        cfather -> right = child -> left;
      }
      delete child;
    }
  } else if (ptr && ptr -> ele == ele) {
    node *child = ptr -> left;
    if (child == NULL) {
      father -> ele > ele ? father -> left = ptr -> right : father -> right = ptr -> right;
      delete ptr;
    } else {
      node *cfather = ptr;
      if (child -> right == NULL) {
        ptr -> ele = child -> ele;
        ptr -> left = child -> left;
        delete child;
        return;
      }
      while (child -> right) {
        cfather = child;
        child = child -> right;
      }
      ptr -> ele = child -> ele;
      cfather -> right = child -> left;
      delete child;
    }
  }
}  // 暗值删除
void BinaryTree::print() {
  preorder(root);
  std::cout << std::endl;
}