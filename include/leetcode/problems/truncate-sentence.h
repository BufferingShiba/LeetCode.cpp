#ifndef LEETCODE_PROBLEMS_TRUNCATE_SENTENCE_H__
#define LEETCODE_PROBLEMS_TRUNCATE_SENTENCE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1816 {

using Func = std::function<std::string(std::string, int)>;

class TruncateSentenceSolution : public SolutionBase<Func> {
 public:
  TruncateSentenceSolution();

  std::string truncateSentence(std::string s, int k);
};

}  // namespace leetcode::problem_1816

#endif  // LEETCODE_PROBLEMS_TRUNCATE_SENTENCE_H__
