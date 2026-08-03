#ifndef LEETCODE_PROBLEMS_CHECK_IF_NUMBERS_ARE_ASCENDING_IN_A_SENTENCE_H__
#define LEETCODE_PROBLEMS_CHECK_IF_NUMBERS_ARE_ASCENDING_IN_A_SENTENCE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2042 {

using Func = std::function<bool(std::string)>;

class CheckIfNumbersAreAscendingInASentenceSolution
    : public SolutionBase<Func> {
 public:
  CheckIfNumbersAreAscendingInASentenceSolution();

  bool areNumbersAscending(std::string s);
};

}  // namespace problem_2042
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_NUMBERS_ARE_ASCENDING_IN_A_SENTENCE_H__
