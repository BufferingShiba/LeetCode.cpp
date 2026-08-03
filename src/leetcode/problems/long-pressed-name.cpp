#include "leetcode/problems/long-pressed-name.h"

namespace leetcode {
namespace problem_925 {

namespace {

bool isLongPressedNameImpl(std::string name, std::string typed) {
  int i = 0;
  int j = 0;
  int n = name.size();
  int m = typed.size();
  while (j < m) {
    if (i < n && name[i] == typed[j]) {
      ++i;
      ++j;
    } else if (j > 0 && typed[j] == typed[j - 1]) {
      ++j;
    } else {
      return false;
    }
  }
  return i == n;
}

}  // namespace

bool LongPressedNameSolution::isLongPressedName(std::string name,
                                                std::string typed) {
  return getSolution()(std::move(name), std::move(typed));
}

LongPressedNameSolution::LongPressedNameSolution() {
  setMetaInfo({925, "Long Pressed Name",
               "https://leetcode.com/problems/long-pressed-name/"});
  registerStrategy({"TwoPointers", "Accepted", "O(n)", "O(1)",
                     {"Two Pointers", "String"}},
                    isLongPressedNameImpl);
}

}  // namespace problem_925
}  // namespace leetcode
