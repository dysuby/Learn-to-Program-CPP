#ifndef MP_H
#define MP_H
#define MAX_INIT 0
namespace MP {
struct TreeNode {
  int weight, id;
  bool visited;
  TreeNode *left, *right;
  TreeNode(int wei, int i): weight(wei), id(i) {
    left = 0;
    right = 0;
    visited = false;
  }
};

class MaxPath {
  private:
    int max;
  public:
    MaxPath() : max(MAX_INIT) {}
    int findMaxPath(TreeNode *root);
};
}  // namespace MP
#endif