#ifndef LEETCODE_PROBLEMS_MAXIMUM_GOOD_PEOPLE_BASED_ON_STATEMENTS_H_
#define LEETCODE_PROBLEMS_MAXIMUM_GOOD_PEOPLE_BASED_ON_STATEMENTS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2151 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumGoodPeopleBasedOnStatementsSolution
    : public SolutionBase<Func> {
 public:
  MaximumGoodPeopleBasedOnStatementsSolution();

  int maximumGood(std::vector<std::vector<int>>& statements);
};

}  // namespace problem_2151
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_GOOD_PEOPLE_BASED_ON_STATEMENTS_H_
