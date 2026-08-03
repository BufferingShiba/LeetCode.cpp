#ifndef LEETCODE_PROBLEMS_SPLIT_THE_ARRAY_H_
#define LEETCODE_PROBLEMS_SPLIT_THE_ARRAY_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3046 {

using Func = std::function<bool(std::vector<int>&)>;

class SplitTheArraySolution : public SolutionBase<Func> {
 public:
  SplitTheArraySolution();

  bool isPossibleToSplit(std::vector<int>& nums);
};

}  // namespace problem_3046
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLIT_THE_ARRAY_H_
