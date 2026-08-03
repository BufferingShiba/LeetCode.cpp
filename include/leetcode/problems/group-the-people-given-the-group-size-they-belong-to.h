#ifndef LEETCODE_PROBLEMS_GROUP_THE_PEOPLE_GIVEN_THE_GROUP_SIZE_THEY_BELONG_TO_H
#define LEETCODE_PROBLEMS_GROUP_THE_PEOPLE_GIVEN_THE_GROUP_SIZE_THEY_BELONG_TO_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1282 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&)>;

class GroupThePeopleGivenTheGroupSizeTheyBelongToSolution
    : public SolutionBase<Func> {
 public:
  GroupThePeopleGivenTheGroupSizeTheyBelongToSolution();

  std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes);
};

}  // namespace problem_1282
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GROUP_THE_PEOPLE_GIVEN_THE_GROUP_SIZE_THEY_BELONG_TO_H
