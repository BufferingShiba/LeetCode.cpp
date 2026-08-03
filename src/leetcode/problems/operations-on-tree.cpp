#include "leetcode/problems/operations-on-tree.h"

namespace leetcode {
namespace problem_1993 {

LockingTree::LockingTree(std::vector<int>& parent) {
  int n = static_cast<int>(parent.size());
  parent_ = parent;
  children_.resize(n);
  locked_.resize(n, 0);
  for (int i = 1; i < n; ++i) {
    children_[parent[i]].push_back(i);
  }
}

bool LockingTree::lock(int num, int user) {
  if (locked_[num] != 0) return false;
  locked_[num] = user;
  return true;
}

bool LockingTree::unlock(int num, int user) {
  if (locked_[num] != user) return false;
  locked_[num] = 0;
  return true;
}

bool LockingTree::upgrade(int num, int user) {
  // Condition 1: the node is unlocked
  if (locked_[num] != 0) return false;

  // Condition 3: it does not have any locked ancestors
  int cur = parent_[num];
  while (cur != -1) {
    if (locked_[cur] != 0) return false;
    cur = parent_[cur];
  }

  // Condition 2: it has at least one locked descendant (by any user)
  // Also unlock all descendants during the same traversal
  bool hasLocked = false;
  unlockDescendants(num, hasLocked);
  if (!hasLocked) return false;

  locked_[num] = user;
  return true;
}

void LockingTree::unlockDescendants(int node, bool& hasLocked) {
  for (int child : children_[node]) {
    if (locked_[child] != 0) {
      hasLocked = true;
      locked_[child] = 0;
    }
    unlockDescendants(child, hasLocked);
  }
}

}  // namespace problem_1993
}  // namespace leetcode
