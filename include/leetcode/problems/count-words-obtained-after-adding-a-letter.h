// LeetCode problem 2135: Count Words Obtained After Adding a Letter
#ifndef LEETCODE_PROBLEMS_COUNT_WORDS_OBTAINED_AFTER_ADDING_A_LETTER_H__
#define LEETCODE_PROBLEMS_COUNT_WORDS_OBTAINED_AFTER_ADDING_A_LETTER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2135 {

using Func = std::function<int(std::vector<std::string>&, std::vector<std::string>&)>;

class CountWordsObtainedAfterAddingALetterSolution
    : public SolutionBase<Func> {
 public:
  CountWordsObtainedAfterAddingALetterSolution();

  int wordCount(std::vector<std::string>& startWords,
                std::vector<std::string>& targetWords);
};

}  // namespace problem_2135
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_WORDS_OBTAINED_AFTER_ADDING_A_LETTER_H__
