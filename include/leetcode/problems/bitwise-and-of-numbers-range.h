#ifndef LEETCODE_PROBLEMS_BITWISE_AND_OF_NUMBERS_RANGE_H_
#define LEETCODE_PROBLEMS_BITWISE_AND_OF_NUMBERS_RANGE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_201 {

using Func = std::function<int(int, int)>;

class BitwiseAndOfNumbersRangeSolution : public SolutionBase<Func> {
 public:
  BitwiseAndOfNumbersRangeSolution();

  int rangeBitwiseAnd(int left, int right);
};

}  // namespace problem_201
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BITWISE_AND_OF_NUMBERS_RANGE_H_
