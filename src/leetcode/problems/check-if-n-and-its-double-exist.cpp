#include "leetcode/problems/check-if-n-and-its-double-exist.h"

#include <unordered_set>

namespace leetcode {
namespace problem_1346 {
namespace {

bool checkIfExistImpl(std::vector<int>& arr) {
  std::unordered_set<int> seen;
  for (int x : arr) {
    if (seen.count(2 * x)) {
      return true;
    }
    if (x % 2 == 0 && seen.count(x / 2)) {
      return true;
    }
    seen.insert(x);
  }
  return false;
}

}  // namespace

CheckIfNAndItsDoubleExistSolution::CheckIfNAndItsDoubleExistSolution() {
  setMetaInfo({.id = 1346,
               .title = "Check If N and Its Double Exist",
               .url = "https://leetcode.com/problems/check-if-n-and-its-double-exist/"});
  registerStrategy({.name = "HashSet",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   checkIfExistImpl);
}

}  // namespace problem_1346
}  // namespace leetcode
