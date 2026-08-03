#ifndef LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_COPY_ARRAYS_H_
#define LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_COPY_ARRAYS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3468 {

using Func = std::function<int(std::vector<int>&, std::vector<std::vector<int>>&)>;

class FindTheNumberOfCopyArraysSolution : public SolutionBase<Func> {
 public:
  FindTheNumberOfCopyArraysSolution();

  int countArrays(std::vector<int>& original, std::vector<std::vector<int>>& bounds);
};

}  // namespace problem_3468
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_COPY_ARRAYS_H_
