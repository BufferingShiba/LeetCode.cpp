#ifndef LEETCODE_PROBLEMS_THE_NUMBER_OF_GOOD_SUBSETS_H__
#define LEETCODE_PROBLEMS_THE_NUMBER_OF_GOOD_SUBSETS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1994 {

using Func = std::function<int(std::vector<int>&)>;

class TheNumberOfGoodSubsetsSolution : public SolutionBase<Func> {
 public:
  TheNumberOfGoodSubsetsSolution();

  int numberOfGoodSubsets(std::vector<int>& nums);
};

}  // namespace problem_1994
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_THE_NUMBER_OF_GOOD_SUBSETS_H__
