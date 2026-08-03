#ifndef LEETCODE_PROBLEMS_SELF_DIVIDING_NUMBERS_H__
#define LEETCODE_PROBLEMS_SELF_DIVIDING_NUMBERS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_728 {

using Func = std::function<std::vector<int>(int, int)>;

class SelfDividingNumbersSolution : public SolutionBase<Func> {
 public:
  SelfDividingNumbersSolution();

  std::vector<int> selfDividingNumbers(int left, int right);
};

}  // namespace problem_728
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SELF_DIVIDING_NUMBERS_H__
