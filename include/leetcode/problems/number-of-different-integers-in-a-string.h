#ifndef LEETCODE_PROBLEMS_NUMBER_OF_DIFFERENT_INTEGERS_IN_A_STRING_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_DIFFERENT_INTEGERS_IN_A_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1805 {

using Func = std::function<int(std::string)>;

class NumberOfDifferentIntegersInAStringSolution
    : public SolutionBase<Func> {
 public:
  NumberOfDifferentIntegersInAStringSolution();

  int numDifferentIntegers(std::string word);
};

}  // namespace problem_1805
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_DIFFERENT_INTEGERS_IN_A_STRING_H_
