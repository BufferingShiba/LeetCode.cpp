#ifndef LEETCODE_PROBLEMS_NUMBER_OF_PEOPLE_AWARE_OF_A_SECRET_H
#define LEETCODE_PROBLEMS_NUMBER_OF_PEOPLE_AWARE_OF_A_SECRET_H

#include "leetcode/core.h"

namespace leetcode::problem_2327 {

class NumberOfPeopleAwareOfASecretSolution
    : public SolutionBase<std::function<int(int, int, int)>> {
 public:
  NumberOfPeopleAwareOfASecretSolution();
  int peopleAwareOfSecret(int n, int delay, int forget);
};

}  // namespace leetcode::problem_2327

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_PEOPLE_AWARE_OF_A_SECRET_H
