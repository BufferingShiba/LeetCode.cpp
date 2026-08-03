#ifndef LEETCODE_PROBLEMS_LONGEST_WORD_IN_DICTIONARY_H__
#define LEETCODE_PROBLEMS_LONGEST_WORD_IN_DICTIONARY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_720 {

using Func = std::function<std::string(std::vector<std::string>&)>;

class LongestWordInDictionarySolution
    : public SolutionBase<Func> {
 public:
  LongestWordInDictionarySolution();

  std::string longestWord(std::vector<std::string>& words);
};

}  // namespace leetcode::problem_720

#endif  // LEETCODE_PROBLEMS_LONGEST_WORD_IN_DICTIONARY_H__
