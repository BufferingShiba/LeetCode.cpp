#ifndef LEETCODE_PROBLEMS_DISTRIBUTE_CANDIES_TO_PEOPLE_H__
#define LEETCODE_PROBLEMS_DISTRIBUTE_CANDIES_TO_PEOPLE_H__

#include "leetcode/core.h"

namespace leetcode::problem_1103 {

using Func = std::function<std::vector<int>(int candies, int num_people)>;

class DistributeCandiesToPeopleSolution
    : public SolutionBase<Func> {
 public:
  DistributeCandiesToPeopleSolution();

  std::vector<int> distributeCandies(int candies, int num_people);
};

}  // namespace leetcode::problem_1103

#endif  // LEETCODE_PROBLEMS_DISTRIBUTE_CANDIES_TO_PEOPLE_H__
