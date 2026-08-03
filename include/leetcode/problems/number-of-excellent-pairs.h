#ifndef LEETCODE_PROBLEMS_NUMBER_OF_EXCELLENT_PAIRS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_EXCELLENT_PAIRS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2354 {

using Func = std::function<long long(std::vector<int>&, int)>;

class NumberOfExcellentPairsSolution : public SolutionBase<Func> {
 public:
  NumberOfExcellentPairsSolution();

  long long countExcellentPairs(std::vector<int>& nums, int k);
};

}  // namespace problem_2354
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_EXCELLENT_PAIRS_H__
