#ifndef LEETCODE_PROBLEMS_LENGTH_OF_LONGEST_V_SHAPED_DIAGONAL_SEGMENT_H__
#define LEETCODE_PROBLEMS_LENGTH_OF_LONGEST_V_SHAPED_DIAGONAL_SEGMENT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3459 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class LengthOfLongestVShapedDiagonalSegmentSolution
    : public SolutionBase<Func> {
 public:
  LengthOfLongestVShapedDiagonalSegmentSolution() {
    setMetaInfo({
        .id = 3459,
        .title = "Length of Longest V-Shaped Diagonal Segment",
        .url = "https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/",
    });
    Func f = [this](std::vector<std::vector<int>>& grid) -> int {
      return lenOfVDiagonal(grid);
    };
    registerStrategy(
        {
            .name = "DiagonalArmDP",
            .expected = "Accepted",
            .time_complexity = "O(n*m)",
            .space_complexity = "O(n*m)",
            .tags = {"Dynamic Programming", "Matrix", "Memoization"},
            .notes =
                "Precompute for every cell and diagonal direction the longest arm "
                "matching alternating 0/2 phases, then enumerate turning points.",
        },
        f);
  }

  int lenOfVDiagonal(std::vector<std::vector<int>>& grid);

  int solution(std::vector<std::vector<int>>& grid) {
    return getSolution()(grid);
  }
};

}  // namespace problem_3459
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LENGTH_OF_LONGEST_V_SHAPED_DIAGONAL_SEGMENT_H__
