#include "MP.hpp"
#include <stack>
using namespace MP;
using std::stack;

int MaxPath::findMaxPath(TreeNode *root) {
  if (root == 0)
    return 0;
  TreeNode *current = root;
  int temp = 0;
  while (root -> visited == false) {
    bool l_alive = false, r_alive = false;
    bool lv = true, rv = true; 
    if (current) {
      r_alive = (current -> right != 0);
      l_alive = (current -> left != 0);
      temp += current -> weight;
      if (l_alive)
        lv = current -> left -> visited;
      if (r_alive)
        rv = current -> right -> visited;
      if (rv && lv) {
        current -> visited = true;
        if (l_alive || r_alive) {
          temp = 0;
          current = root;
        }
      }
      if (l_alive && !lv)
        current = current -> left;
      else if (r_alive && !rv)
        current = current -> right;
      if (!l_alive && !r_alive) {
        max = max > temp ? max : temp;
        temp = 0;
        current = root;
      }
    }
  }
  return max;
}