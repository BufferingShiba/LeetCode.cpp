#ifndef LEETCODE_PROBLEMS_BITWISE_OR_OF_EVEN_NUMBERS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_BITWISE_OR_OF_EVEN_NUMBERS_IN_AN_ARRAY_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3688 {

using Func = std::function<int(std::vector<int>&)>;

class BitwiseOrOfEvenNumbersInAnArraySolution
    : public SolutionBase<Func> {
 public:
  BitwiseOrOfEvenNumbersInAnArraySolution();

  int evenNumberBitwiseORs(std::vector<int>& nums);
};

}  // namespace problem_3688
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BITWISE_OR_OF_EVEN_NUMBERS_IN_AN_ARRAY_H__
