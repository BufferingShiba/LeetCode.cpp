#include "leetcode/problems/defuse-the-bomb.h"

namespace leetcode {
namespace problem_1652 {
namespace {

std::vector<int> decryptImpl(std::vector<int>& code, int k) {
  int n = static_cast<int>(code.size());
  if (k == 0) {
    return std::vector<int>(n, 0);
  }

  std::vector<int> result(n, 0);
  if (k > 0) {
    // For index i, sum of next k numbers: code[(i+1)%n] ... code[(i+k)%n].
    int window = 0;
    for (int j = 1; j <= k; ++j) {
      window += code[j % n];
    }
    result[0] = window;
    for (int i = 1; i < n; ++i) {
      window -= code[i % n];
      window += code[(i + k) % n];
      result[i] = window;
    }
  } else {
    // For index i, sum of previous |k| numbers: code[(i-1+n)%n] ... code[(i-k+n)%n].
    int m = -k;
    int window = 0;
    for (int j = 1; j <= m; ++j) {
      window += code[(0 - j + n) % n];
    }
    result[0] = window;
    for (int i = 1; i < n; ++i) {
      window -= code[(i - m - 1 + n) % n];
      window += code[(i - 1 + n) % n];
      result[i] = window;
    }
  }
  return result;
}

}  // namespace

DefuseTheBombSolution::DefuseTheBombSolution() : SolutionBase<Func>() {
  setMetaInfo({.id = 1652, .title = "Defuse the Bomb", .url = "https://leetcode.com/problems/defuse-the-bomb/"});
  registerStrategy({.name = "SlidingWindow", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Array", "Sliding Window"}}, decryptImpl);
}

std::vector<int> DefuseTheBombSolution::decrypt(std::vector<int>& code, int k) {
  return getSolution()(code, k);
}

}  // namespace problem_1652
}  // namespace leetcode
