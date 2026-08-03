#ifndef LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_H__
#define LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_217 {

using Func = std::function<bool(std::vector<int>&)>;

class ContainsDuplicateSolution : public SolutionBase<Func> {
 public:
  ContainsDuplicateSolution();
  bool containsDuplicate(std::vector<int>& nums);
};

}  // namespace problem_217
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_H__
