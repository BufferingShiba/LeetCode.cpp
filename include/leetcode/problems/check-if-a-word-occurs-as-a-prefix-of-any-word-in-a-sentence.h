#ifndef LEETCODE_PROBLEMS_CHECK_IF_A_WORD_OCCURS_AS_A_PREFIX_OF_ANY_WORD_IN_A_SENTENCE_H__
#define LEETCODE_PROBLEMS_CHECK_IF_A_WORD_OCCURS_AS_A_PREFIX_OF_ANY_WORD_IN_A_SENTENCE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1455 {

using Func = std::function<int(const std::string&, const std::string&)>;

class CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution
    : public SolutionBase<Func> {
 public:
  CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution();
  int isPrefixOfWord(const std::string& sentence,
                     const std::string& searchWord);
};

}  // namespace leetcode::problem_1455

#endif  // LEETCODE_PROBLEMS_CHECK_IF_A_WORD_OCCURS_AS_A_PREFIX_OF_ANY_WORD_IN_A_SENTENCE_H__
