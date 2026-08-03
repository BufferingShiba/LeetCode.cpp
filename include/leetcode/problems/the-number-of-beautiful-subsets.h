#ifndef LEETCODE_PROBLEMS_THE_NUMBER_OF_BEAUTIFUL_SUBSETS_H__
#define LEETCODE_PROBLEMS_THE_NUMBER_OF_BEAUTIFUL_SUBSETS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2597 {

using Func = std::function<int(std::vector<int>&, int)>;

class TheNumberOfBeautifulSubsetsSolution
    : public SolutionBase<Func> {
 public:
  TheNumberOfBeautifulSubsetsSolution();

  int beautifulSubsets(std::vector<int>& nums, int k);
};

}  // namespace problem_2597
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_THE_NUMBER_OF_BEAUTIFUL_SUBSETS_H__
