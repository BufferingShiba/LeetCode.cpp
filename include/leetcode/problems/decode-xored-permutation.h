#ifndef LEETCODE_PROBLEMS_DECODE_XORED_PERMUTATION_H_
#define LEETCODE_PROBLEMS_DECODE_XORED_PERMUTATION_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1734 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class DecodeXoredPermutationSolution : public SolutionBase<Func> {
 public:
  std::vector<int> decode(std::vector<int>& encoded);

  DecodeXoredPermutationSolution();
};

}  // namespace problem_1734
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DECODE_XORED_PERMUTATION_H_
