#ifndef LEETCODE_PROBLEMS_FIND_MISSING_ELEMENTS_H__
#define LEETCODE_PROBLEMS_FIND_MISSING_ELEMENTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3731 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindMissingElementsSolution : public SolutionBase<Func> {
 public:
  std::vector<int> findMissingElements(std::vector<int>& nums);

  FindMissingElementsSolution();
};

}  // namespace problem_3731
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MISSING_ELEMENTS_H__
