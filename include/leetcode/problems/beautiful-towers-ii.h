#ifndef LEETCODE_PROBLEMS_BEAUTIFUL_TOWERS_II_H__
#define LEETCODE_PROBLEMS_BEAUTIFUL_TOWERS_II_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2866 {

using Func = std::function<long long(std::vector<int>&)>;

class BeautifulTowersIiSolution : public SolutionBase<Func> {
 public:
  BeautifulTowersIiSolution();

  long long call(std::vector<int>& maxHeights);
};

}  // namespace leetcode::problem_2866

#endif  // LEETCODE_PROBLEMS_BEAUTIFUL_TOWERS_II_H__
