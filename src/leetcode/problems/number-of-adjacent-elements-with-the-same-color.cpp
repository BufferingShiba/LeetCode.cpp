#include "leetcode/problems/number-of-adjacent-elements-with-the-same-color.h"

namespace leetcode {
namespace problem_2672 {

static std::vector<int> colorTheArrayImpl(int n,
                                          std::vector<std::vector<int>>& queries) {
  std::vector<int> colors(n, 0);
  std::vector<int> answer;
  answer.reserve(queries.size());
  int count = 0;

  for (const auto& q : queries) {
    int idx = q[0];
    int new_color = q[1];
    int old_color = colors[idx];

    if (old_color == new_color) {
      answer.push_back(count);
      continue;
    }

    // check left neighbor (idx-1, idx)
    if (idx > 0) {
      int left_color = colors[idx - 1];
      // remove old contribution
      if (old_color != 0 && left_color == old_color) {
        --count;
      }
      // add new contribution
      if (new_color != 0 && left_color == new_color) {
        ++count;
      }
    }

    // check right neighbor (idx, idx+1)
    if (idx < n - 1) {
      int right_color = colors[idx + 1];
      // remove old contribution
      if (old_color != 0 && right_color == old_color) {
        --count;
      }
      // add new contribution
      if (new_color != 0 && right_color == new_color) {
        ++count;
      }
    }

    colors[idx] = new_color;
    answer.push_back(count);
  }

  return answer;
}

NumberOfAdjacentElementsWithTheSameColorSolution::
    NumberOfAdjacentElementsWithTheSameColorSolution() {
  setMetaInfo({.id = 2672,
               .title = "Number of Adjacent Elements With the Same Color",
               .url = "https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/"});

  registerStrategy(
      {.name = "Incremental Update",
       .expected = "Accepted",
       .time_complexity = "O(n + q)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      colorTheArrayImpl);
}

std::vector<int> NumberOfAdjacentElementsWithTheSameColorSolution::colorTheArray(
    int n, std::vector<std::vector<int>>& queries) {
  return getSolution()(n, queries);
}

}  // namespace problem_2672
}  // namespace leetcode
