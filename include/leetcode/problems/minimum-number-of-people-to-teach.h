#ifndef LEETCODE_MINIMUM_NUMBER_OF_PEOPLE_TO_TEACH_H__
#define LEETCODE_MINIMUM_NUMBER_OF_PEOPLE_TO_TEACH_H__

#include "leetcode/core.h"

#include <vector>

namespace leetcode {
namespace problem_1733 {

using Func = std::function<int(int, std::vector<std::vector<int>>&,
                               std::vector<std::vector<int>>&)>;

class MinimumNumberOfPeopleToTeachSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfPeopleToTeachSolution();

  int minimumTeachings(int n, std::vector<std::vector<int>>& languages,
                       std::vector<std::vector<int>>& friendships);
};

}  // namespace problem_1733
}  // namespace leetcode

#endif  // LEETCODE_MINIMUM_NUMBER_OF_PEOPLE_TO_TEACH_H__
