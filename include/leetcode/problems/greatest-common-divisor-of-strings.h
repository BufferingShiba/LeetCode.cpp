#ifndef LEETCODE_PROBLEMS_GREATEST_COMMON_DIVISOR_OF_STRINGS_H_
#define LEETCODE_PROBLEMS_GREATEST_COMMON_DIVISOR_OF_STRINGS_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1071 {

using Func = std::function<std::string(std::string, std::string)>;

class GreatestCommonDivisorOfStringsSolution : public SolutionBase<Func> {
 public:
  GreatestCommonDivisorOfStringsSolution();

  std::string gcdOfStrings(std::string str1, std::string str2);
};

}  // namespace problem_1071
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GREATEST_COMMON_DIVISOR_OF_STRINGS_H_
