#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_MAKE_ARRAY_COMPLEMENTARY_H__
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_MAKE_ARRAY_COMPLEMENTARY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1674 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumMovesToMakeArrayComplementarySolution
    : public SolutionBase<Func> {
 public:
  MinimumMovesToMakeArrayComplementarySolution();

  int minMoves(std::vector<int>& nums, int limit);
};

}  // namespace problem_1674
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_MAKE_ARRAY_COMPLEMENTARY_H__
