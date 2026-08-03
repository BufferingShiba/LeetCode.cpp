#ifndef LEETCODE_PROBLEMS_MAXIMUM_ELEGANCE_OF_A_K_LENGTH_SUBSEQUENCE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_ELEGANCE_OF_A_K_LENGTH_SUBSEQUENCE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2813 {

using Func = std::function<long long(std::vector<std::vector<int>>&, int)>;

class MaximumEleganceOfAKLengthSubsequenceSolution
    : public SolutionBase<Func> {
 public:
  MaximumEleganceOfAKLengthSubsequenceSolution();
  long long findMaximumElegance(std::vector<std::vector<int>>& items, int k);
};

}  // namespace problem_2813
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_ELEGANCE_OF_A_K_LENGTH_SUBSEQUENCE_H__
