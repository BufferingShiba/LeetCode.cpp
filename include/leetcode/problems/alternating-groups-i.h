#ifndef LEETCODE_PROBLEMS_ALTERNATING_GROUPS_I_H__
#define LEETCODE_PROBLEMS_ALTERNATING_GROUPS_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3206 {

using Func = std::function<int(std::vector<int>&)>;

class AlternatingGroupsISolution : public SolutionBase<Func> {
 public:
  AlternatingGroupsISolution();

  int numberOfAlternatingGroups(std::vector<int>& colors);
};

}  // namespace problem_3206
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ALTERNATING_GROUPS_I_H__
