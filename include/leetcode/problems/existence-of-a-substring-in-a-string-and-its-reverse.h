#ifndef LEETCODE_PROBLEMS_EXISTENCE_OF_A_SUBSTRING_IN_A_STRING_AND_ITS_REVERSE_H__
#define LEETCODE_PROBLEMS_EXISTENCE_OF_A_SUBSTRING_IN_A_STRING_AND_ITS_REVERSE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3083 {

using Func = std::function<bool(std::string)>;

class ExistenceOfASubstringInAStringAndItsReverseSolution
    : public SolutionBase<Func> {
 public:
  ExistenceOfASubstringInAStringAndItsReverseSolution();

  bool isSubstringPresent(std::string s);
};

}  // namespace problem_3083
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_EXISTENCE_OF_A_SUBSTRING_IN_A_STRING_AND_ITS_REVERSE_H__
