#ifndef LEETCODE_PROBLEMS_MOST_FREQUENT_NUMBER_FOLLOWING_KEY_IN_AN_ARRAY_H_
#define LEETCODE_PROBLEMS_MOST_FREQUENT_NUMBER_FOLLOWING_KEY_IN_AN_ARRAY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2190 {

using Func = std::function<int(std::vector<int>&, int)>;

class MostFrequentNumberFollowingKeyInAnArraySolution
    : public SolutionBase<Func> {
 public:
  MostFrequentNumberFollowingKeyInAnArraySolution();

  int mostFrequent(std::vector<int>& nums, int key);
};

}  // namespace problem_2190
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOST_FREQUENT_NUMBER_FOLLOWING_KEY_IN_AN_ARRAY_H_
