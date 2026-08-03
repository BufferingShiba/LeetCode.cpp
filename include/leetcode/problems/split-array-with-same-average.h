#ifndef LEETCODE_PROBLEMS_SPLIT_ARRAY_WITH_SAME_AVERAGE_H__
#define LEETCODE_PROBLEMS_SPLIT_ARRAY_WITH_SAME_AVERAGE_H__

#include <vector>
#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_805 {

using Func = std::function<bool(std::vector<int>&)>;

class SplitArrayWithSameAverageSolution : public SolutionBase<Func> {
 public:
  SplitArrayWithSameAverageSolution();

  bool splitArraySameAverage(std::vector<int>& nums);
};

}  // namespace problem_805
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLIT_ARRAY_WITH_SAME_AVERAGE_H__
