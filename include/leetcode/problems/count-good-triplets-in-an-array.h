#ifndef LEETCODE_PROBLEMS_COUNT_GOOD_TRIPLETS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_COUNT_GOOD_TRIPLETS_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2179 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&)>;

class CountGoodTripletsInAnArraySolution
    : public SolutionBase<Func> {
 public:
  CountGoodTripletsInAnArraySolution();

  long long goodTriplets(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace leetcode::problem_2179

#endif  // LEETCODE_PROBLEMS_COUNT_GOOD_TRIPLETS_IN_AN_ARRAY_H__
