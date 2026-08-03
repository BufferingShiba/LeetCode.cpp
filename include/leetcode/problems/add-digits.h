#ifndef LEETCODE_PROBLEMS_ADD_DIGITS_H__
#define LEETCODE_PROBLEMS_ADD_DIGITS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_258 {

using Func = std::function<int(int)>;

class AddDigitsSolution : public SolutionBase<Func> {
 public:
  AddDigitsSolution();

  int addDigits(int num);
};

}  // namespace problem_258
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ADD_DIGITS_H__
