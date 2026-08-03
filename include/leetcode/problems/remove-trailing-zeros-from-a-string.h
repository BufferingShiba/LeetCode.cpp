#ifndef LEETCODE_PROBLEMS_REMOVE_TRAILING_ZEROS_FROM_A_STRING_H__
#define LEETCODE_PROBLEMS_REMOVE_TRAILING_ZEROS_FROM_A_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2710 {

using Func = std::function<std::string(std::string)>;

class RemoveTrailingZerosFromAStringSolution
    : public SolutionBase<Func> {
 public:
  RemoveTrailingZerosFromAStringSolution();

  std::string removeTrailingZeros(std::string num);
};

}  // namespace problem_2710
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_TRAILING_ZEROS_FROM_A_STRING_H__
