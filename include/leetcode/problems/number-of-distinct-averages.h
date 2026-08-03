#ifndef LEETCODE_PROBLEMS_NUMBER_OF_DISTINCT_AVERAGES_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_DISTINCT_AVERAGES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2465 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfDistinctAveragesSolution : public SolutionBase<Func> {
 public:
  NumberOfDistinctAveragesSolution();

  int distinctAverages(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2465

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_DISTINCT_AVERAGES_H__
