#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_WORDS_YOU_CAN_TYPE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_WORDS_YOU_CAN_TYPE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_1935 {

using Func = std::function<int(std::string, std::string)>;

class MaximumNumberOfWordsYouCanTypeSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfWordsYouCanTypeSolution();

  int canBeTypedWords(std::string text, std::string brokenLetters);
};

}  // namespace leetcode::problem_1935

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_WORDS_YOU_CAN_TYPE_H__
