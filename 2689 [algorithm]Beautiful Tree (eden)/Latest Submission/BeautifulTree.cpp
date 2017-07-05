#include <algorithm>
#include <vector>
#include "BeautifulTree.hpp"
using namespace HFM;

HuffmanCode::HuffmanCode(const string &str): isString(true) {
  for (auto &i: str) {
    if (i != ' ') {
      ++weight[i];
      origin.append(1, i);
    }
  }
  BuildTree();
}

HuffmanCode::HuffmanCode(int w[], int n): isString(false) {
  for (int index = 0; index < n; ++index)
    weight[static_cast<char>(weight[index] + index)] = w[index];
  BuildTree();
}

bool HuffmanCode::cmp(pair<char, int> l, pair<char, int> r) {
  if (l.second < r.second)
    return true;
  else if (l.second == r.second)
    if (res[l.first].size() > res[r.first].size())
      return true;
    else if (res[l.first].size() == res[r.first].size())
      return res[l.first] > res[r.first];
  return false;
}

void HuffmanCode::DisplayCode() {
    vector<pair<char, int>> sorted;
    for (auto i: weight)
      sorted.push_back(i);
    sort(sorted.begin(), sorted.end(), 
        [](pair<char, int> r, pair<char, int> l)
        {return (r.second < l.second) 
          || ((r.second == l.second) && (r.first < l.first));});
  if (isString) {
    int size(0);
    string resString;
    for (auto i: sorted){      
      cout << "(" << i.first << ") Weight = ";
      cout << i.second << "; Code = ";
      cout << res[i.first] << endl;
    }
    for (auto &c: origin) {
      resString += res[c];
      size += res[c].size();
    }
    cout << "Huffman's codeLength = " << size << endl;
    cout << "Origin Text: " << origin << endl;
    cout << "Huffman's Code: " << resString << endl;
  } else {
    // vector<pair<char, int>> sorted;
    // for (auto i: weight)
    //   sorted.push_back(i);
    // for (int i = 0; i < sorted.size(); ++i) {
    //   for (int k = i + 1; k < sorted.size(); ++k) {
    //     if (!cmp(sorted[i], sorted[k]))
    //       swap(sorted[i], sorted[k]);
    //   }
    // }
    int size(0);
    for (auto &i: sorted) {
      cout << "Weight = " << i.second;
      cout << "; Code = " << res[i.first] << endl;
      size += (res[i.first].size() * i.second);
    }
    cout << "Huffman's codeLength = " << size << endl;
  }
}

HuffmanCode::~HuffmanCode() {
  clear(root);
  root = 0;
}

void HuffmanCode::clear(Node *root) {
  if (root) {
    clear(root -> left);
    clear(root -> right);
    delete root;
  }
}

void HuffmanCode::BuildTree() {
  vector<Node*> tree;
  for (auto i: weight) {
    Node *temp = new Node(i.second, i.first);
    tree.push_back(temp);
  }
  while (tree.size() > 1) {
    auto temp = min_element(tree.begin(), tree.end(), 
                            [](Node *r, Node* l)
                            {return r -> weight < l -> weight;});
    Node *min(*temp);
    tree.erase(temp);
    temp = min_element(tree.begin(), tree.end(), 
                            [](Node *r, Node* l)
                            {return r -> weight < l -> weight;});
    Node *sec_min(*temp);
    tree.erase(temp);
    Node *newNode = new Node(min -> weight + sec_min -> weight, 0, min, sec_min);
    tree.push_back(newNode);
  }
  if (tree.size())
    root = tree[0];
  translate();
}

void HuffmanCode::translate() {
  if (root) {
    Node *current = root;
    string temp;
    while (root -> visited == false) {
      bool l_alive = false, r_alive = false;
      bool lv = true, rv = true; 
      r_alive = (current -> right != 0);
      l_alive = (current -> left != 0);
      if (l_alive)
        lv = current -> left -> visited;
      if (r_alive)
        rv = current -> right -> visited;
      if (rv && lv) {
        current -> visited = true;
        if (l_alive || r_alive) {
          temp = "";
          current = root;
        }
      }
      if (l_alive && !lv) {
        current = current -> left;
        temp += "1";
      }
      else if (r_alive && !rv) {
        current = current -> right;
        temp += "0";
      }
      if (!l_alive && !r_alive) {
        res[current -> ch] = temp;
        temp = "";
        current = root;
      }
    }
  }
}