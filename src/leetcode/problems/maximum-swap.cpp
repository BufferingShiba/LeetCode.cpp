#include "leetcode/problems/maximum-swap.h"

#include <algorithm>
#include <array>
#include <string>

namespace leetcode::problem_670 {

MaximumSwapSolution::MaximumSwapSolution() {
  setMetaInfo({.id = 670, .title = "Maximum Swap", .url = "https://leetcode.com/problems/maximum-swap/"});
  registerStrategy(
      {.name = "GreedyRightmostLarger",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Greedy"}},
      [](int num) {
        std::string digits = std::to_string(num);
        const int n = static_cast<int>(digits.size());

        // last[c] = rightmost index where digit c appears in the string.
        std::array<int, 10> last;
        last.fill(-1);
        for (int i = 0; i < n; ++i) {
          last[digits[i] - '0'] = i;
        }

        // Left to right, at each position try to swap the current digit with the
        // largest digit among positions to its right. Picking the rightmost
        // occurrence of that larger digit yields the maximum value.
        for (int i = 0; i < n; ++i) {
          for (int d = 9; d > digits[i] - '0'; --d) {
            if (last[d] > i) {
              std::swap(digits[i], digits[last[d]]);
              return std::stoi(digits);
            }
          }
        }

        return num;
      });
}

int MaximumSwapSolution::maximumSwap(int num) {
  return getSolution()(num);
}

}  // namespace leetcode::problem_670
