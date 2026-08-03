#ifndef LEETCODE_PROBLEMS_KIDS_WITH_THE_GREATEST_NUMBER_OF_CANDIES_H__
#define LEETCODE_PROBLEMS_KIDS_WITH_THE_GREATEST_NUMBER_OF_CANDIES_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1431 {

using Func = std::function<std::vector<bool>(std::vector<int>&, int)>;

class KidsWithTheGreatestNumberOfCandiesSolution
    : public SolutionBase<Func> {
 public:
  KidsWithTheGreatestNumberOfCandiesSolution();

  std::vector<bool> kidsWithCandies(std::vector<int>& candies,
                                    int extraCandies);
};

}  // namespace leetcode::problem_1431

#endif  // LEETCODE_PROBLEMS_KIDS_WITH_THE_GREATEST_NUMBER_OF_CANDIES_H__
