#ifndef BEAUTIFUL_TREE_H
#define BEAUTIFUL_TREE_H
#include <string>
#include <iostream>
#include <map>
using namespace std;

namespace HFM {
  struct Node {
    int weight;
    char ch;
    Node *left, *right;
    bool visited;
    Node(int w = 0, char c = 0, Node *l = 0, Node *r = 0): 
          weight(w), ch(c), left(l), right(r), visited(0) {}
  };
  class HuffmanCode {
    public:
      explicit HuffmanCode(const string &str);
      HuffmanCode(int w[], int n);
      void DisplayCode();
      ~HuffmanCode();
    private:
      map<char, int> weight;
      map<char, string> res;
      Node *root;
      bool isString;
      string origin;
      void BuildTree();
      void translate();
      void clear(Node *root);
      bool cmp(pair<char, int> l, pair<char, int> r);
  };
}

#endif