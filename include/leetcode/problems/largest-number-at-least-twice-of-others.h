#ifndef LEETCODE_PROBLEMS_LARGEST_NUMBER_AT_LEAST_TWICE_OF_OTHERS_H__
#define LEETCODE_PROBLEMS_LARGEST_NUMBER_AT_LEAST_TWICE_OF_OTHERS_H__

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_747 {

using Func = std::function<int(std::vector<int>&)>;

class LargestNumberAtLeastTwiceOfOthersSolution
    : public SolutionBase<Func> {
 public:
  LargestNumberAtLeastTwiceOfOthersSolution();

  int dominantIndex(std::vector<int>& nums);
};

}  // namespace problem_747
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_NUMBER_AT_LEAST_TWICE_OF_OTHERS_H__
