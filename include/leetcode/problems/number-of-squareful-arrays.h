#ifndef LEETCODE_NUMBER_OF_SQUAREFUL_ARRAYS_H_
#define LEETCODE_NUMBER_OF_SQUAREFUL_ARRAYS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_996 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfSquarefulArraysSolution : public SolutionBase<Func> {
 public:
  NumberOfSquarefulArraysSolution();

  int numSquarefulPerms(std::vector<int>& nums);
};

}  // namespace problem_996
}  // namespace leetcode

#endif  // LEETCODE_NUMBER_OF_SQUAREFUL_ARRAYS_H_
