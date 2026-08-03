#ifndef LEETCODE_PROBLEMS_GROUPS_OF_SPECIAL_EQUIVALENT_STRINGS_H__
#define LEETCODE_PROBLEMS_GROUPS_OF_SPECIAL_EQUIVALENT_STRINGS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_893 {

using Func = std::function<int(std::vector<std::string>&)>;

class GroupsOfSpecialEquivalentStringsSolution
    : public SolutionBase<Func> {
 public:
  GroupsOfSpecialEquivalentStringsSolution();

  int numSpecialEquivGroups(std::vector<std::string>& words);
};

}  // namespace problem_893
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GROUPS_OF_SPECIAL_EQUIVALENT_STRINGS_H__
