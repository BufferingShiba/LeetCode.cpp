#ifndef LEETCODE_PROBLEMS_GROUPS_OF_STRINGS_H__
#define LEETCODE_PROBLEMS_GROUPS_OF_STRINGS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2157 {

using Func = std::function<std::vector<int>(std::vector<std::string>&)>;

class GroupsOfStringsSolution : public SolutionBase<Func> {
 public:
  std::vector<int> groupStrings(std::vector<std::string>& words);
  GroupsOfStringsSolution();
};

}  // namespace leetcode::problem_2157

#endif  // LEETCODE_PROBLEMS_GROUPS_OF_STRINGS_H__
