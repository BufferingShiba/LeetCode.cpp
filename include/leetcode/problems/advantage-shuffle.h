#ifndef LEETCODE_PROBLEMS_ADVANTAGE_SHUFFLE_H__
#define LEETCODE_PROBLEMS_ADVANTAGE_SHUFFLE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_870 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class AdvantageShuffleSolution : public SolutionBase<Func> {
 public:
  AdvantageShuffleSolution();

  std::vector<int> advantageCount(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace leetcode::problem_870

#endif  // LEETCODE_PROBLEMS_ADVANTAGE_SHUFFLE_H__
