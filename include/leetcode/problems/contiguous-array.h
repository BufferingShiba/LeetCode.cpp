#ifndef LEETCODE_PROBLEMS_CONTIGUOUS_ARRAY_H__
#define LEETCODE_PROBLEMS_CONTIGUOUS_ARRAY_H__

#include "leetcode/core.h"

#include <vector>

namespace leetcode::problem_525 {

using Func = std::function<int(std::vector<int>&)>;

class ContiguousArraySolution : public SolutionBase<Func> {
 public:
  int findMaxLength(std::vector<int>& nums);

  ContiguousArraySolution() {
    setMetaInfo(
        {.id = 525,
         .title = "Contiguous Array",
         .url = "https://leetcode.com/problems/contiguous-array/"});
    registerStrategy(
        {.name = "prefix-sum",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(n)",
         .tags = {"Array", "Hash Table", "Prefix Sum"}},
        findMaxLengthImpl);
  }

 private:
  static int findMaxLengthImpl(std::vector<int>& nums);
};

}  // namespace leetcode::problem_525

#endif  // LEETCODE_PROBLEMS_CONTIGUOUS_ARRAY_H__
