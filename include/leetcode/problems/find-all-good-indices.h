#ifndef LEETCODE_PROBLEMS_FIND_ALL_GOOD_INDICES_H_
#define LEETCODE_PROBLEMS_FIND_ALL_GOOD_INDICES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2420 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class FindAllGoodIndicesSolution : public SolutionBase<Func> {
 public:
  FindAllGoodIndicesSolution();

  std::vector<int> goodIndices(std::vector<int>& nums, int k);
};

}  // namespace problem_2420
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_ALL_GOOD_INDICES_H_
