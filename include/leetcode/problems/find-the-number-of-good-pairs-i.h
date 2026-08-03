#ifndef LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_GOOD_PAIRS_I_H__
#define LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_GOOD_PAIRS_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3162 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, int)>;

class FindTheNumberOfGoodPairsISolution : public SolutionBase<Func> {
 public:
  FindTheNumberOfGoodPairsISolution();

  int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);
};

}  // namespace problem_3162
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_GOOD_PAIRS_I_H__
