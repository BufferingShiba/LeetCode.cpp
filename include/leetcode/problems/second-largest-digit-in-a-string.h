#ifndef LEETCODE_PROBLEMS_SECOND_LARGEST_DIGIT_IN_A_STRING_H_
#define LEETCODE_PROBLEMS_SECOND_LARGEST_DIGIT_IN_A_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1796 {

using Func = std::function<int(std::string)>;

class SecondLargestDigitInAStringSolution : public SolutionBase<Func> {
 public:
  SecondLargestDigitInAStringSolution();

  int secondHighest(std::string s);
};

}  // namespace problem_1796
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SECOND_LARGEST_DIGIT_IN_A_STRING_H_
