#ifndef LEETCODE_PROBLEMS_CREATE_SORTED_ARRAY_THROUGH_INSTRUCTIONS_H
#define LEETCODE_PROBLEMS_CREATE_SORTED_ARRAY_THROUGH_INSTRUCTIONS_H

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1649 {

using Func = std::function<int(std::vector<int>&)>;

class CreateSortedArrayThroughInstructionsSolution : public SolutionBase<Func> {
 public:
  CreateSortedArrayThroughInstructionsSolution();

  int createSortedArray(std::vector<int>& instructions);
};

}  // namespace problem_1649
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CREATE_SORTED_ARRAY_THROUGH_INSTRUCTIONS_H
