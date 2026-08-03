#ifndef LEETCODE_PROBLEMS_LAST_VISITED_INTEGERS_H__
#define LEETCODE_PROBLEMS_LAST_VISITED_INTEGERS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2899 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class LastVisitedIntegersSolution : public SolutionBase<Func> {
 public:
  LastVisitedIntegersSolution();

  std::vector<int> lastVisitedIntegers(std::vector<int>& nums);
};

}  // namespace problem_2899
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LAST_VISITED_INTEGERS_H__
