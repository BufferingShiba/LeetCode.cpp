#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_WORDS_FOUND_IN_SENTENCES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_WORDS_FOUND_IN_SENTENCES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2114 {

using Func = std::function<int(std::vector<std::string>&)>;

class MaximumNumberOfWordsFoundInSentencesSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfWordsFoundInSentencesSolution();

  int mostWordsFound(std::vector<std::string>& sentences);
};

}  // namespace leetcode::problem_2114

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_WORDS_FOUND_IN_SENTENCES_H__
