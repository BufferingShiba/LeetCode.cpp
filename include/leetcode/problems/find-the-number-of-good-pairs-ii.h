#ifndef LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_GOOD_PAIRS_II_H__
#define LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_GOOD_PAIRS_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3164 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&, int)>;

class FindTheNumberOfGoodPairsIiSolution : public SolutionBase<Func> {
 public:
  FindTheNumberOfGoodPairsIiSolution();

  long long numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);
};

}  // namespace leetcode::problem_3164

#endif  // LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_GOOD_PAIRS_II_H__
