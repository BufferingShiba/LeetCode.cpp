#ifndef LEETCODE_PROBLEM_3514_H_
#define LEETCODE_PROBLEM_3514_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3514 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfUniqueXorTripletsIiSolution : public SolutionBase<Func> {
 public:
  NumberOfUniqueXorTripletsIiSolution();

  int uniqueXorTriplets(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3514

#endif  // LEETCODE_PROBLEM_3514_H_
