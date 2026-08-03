#ifndef LEETCODE_PROBLEMS_NUMBER_OF_BEAUTIFUL_PAIRS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_BEAUTIFUL_PAIRS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2748 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfBeautifulPairsSolution : public SolutionBase<Func> {
 public:
  NumberOfBeautifulPairsSolution();

  int countBeautifulPairs(std::vector<int>& nums);
};

}  // namespace problem_2748
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_BEAUTIFUL_PAIRS_H__
