#ifndef LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_DISTINCT_COLORS_AMONG_THE_BALLS_H__
#define LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_DISTINCT_COLORS_AMONG_THE_BALLS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3160 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&)>;

class FindTheNumberOfDistinctColorsAmongTheBallsSolution
    : public SolutionBase<Func> {
 public:
  FindTheNumberOfDistinctColorsAmongTheBallsSolution();

  std::vector<int> queryResults(int limit,
                                std::vector<std::vector<int>>& queries);
};

}  // namespace problem_3160
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_DISTINCT_COLORS_AMONG_THE_BALLS_H__
