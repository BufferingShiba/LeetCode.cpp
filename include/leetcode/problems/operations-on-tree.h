#ifndef LEETCODE_PROBLEMS_OPERATIONS_ON_TREE_H_
#define LEETCODE_PROBLEMS_OPERATIONS_ON_TREE_H_

#include <vector>

namespace leetcode {
namespace problem_1993 {

class LockingTree {
 public:
  explicit LockingTree(std::vector<int>& parent);

  bool lock(int num, int user);
  bool unlock(int num, int user);
  bool upgrade(int num, int user);

 private:
  void unlockDescendants(int node, bool& hasLocked);

  std::vector<int> parent_;
  std::vector<std::vector<int>> children_;
  std::vector<int> locked_;  // 0 = unlocked, else user id
};

}  // namespace problem_1993
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_OPERATIONS_ON_TREE_H_
