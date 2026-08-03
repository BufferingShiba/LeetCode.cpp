#include "leetcode/problems/validate-binary-tree-nodes.h"

#include <queue>

namespace leetcode {
namespace problem_1361 {

static bool solution1(int n, vector<int>& leftChild, vector<int>& rightChild) {
  vector<int> inDegree(n, 0);
  for (int i = 0; i < n; ++i) {
    if (leftChild[i] != -1 && (++inDegree[leftChild[i]] > 1)) {
      return false;
    }
    if (rightChild[i] != -1 && (++inDegree[rightChild[i]] > 1)) {
      return false;
    }
  }

  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (inDegree[i] == 0) {
      if (root != -1) {
        return false;  // more than one root
      }
      root = i;
    }
  }
  if (root == -1) {
    return false;  // no root => cycle
  }

  vector<bool> visited(n, false);
  std::queue<int> q;
  q.push(root);
  visited[root] = true;
  int count = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ++count;
    int child = leftChild[node];
    if (child != -1) {
      if (visited[child]) {
        return false;  // cycle / already visited
      }
      visited[child] = true;
      q.push(child);
    }
    child = rightChild[node];
    if (child != -1) {
      if (visited[child]) {
        return false;  // cycle / already visited
      }
      visited[child] = true;
      q.push(child);
    }
  }

  return count == n;
}

ValidateBinaryTreeNodesSolution::ValidateBinaryTreeNodesSolution() {
  setMetaInfo({
      .id = 1361,
      .title = "Validate Binary Tree Nodes",
      .url = "https://leetcode.com/problems/validate-binary-tree-nodes"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

bool ValidateBinaryTreeNodesSolution::validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
  return getSolution()(n, leftChild, rightChild);
}

}  // namespace problem_1361
}  // namespace leetcode
