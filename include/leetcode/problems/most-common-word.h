#ifndef LEETCODE_PROBLEMS_MOST_COMMON_WORD_H_
#define LEETCODE_PROBLEMS_MOST_COMMON_WORD_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_819 {

using Func = std::function<std::string(std::string, std::vector<std::string>&)>;

class MostCommonWordSolution : public SolutionBase<Func> {
 public:
  MostCommonWordSolution();
  std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned);
};

}  // namespace leetcode::problem_819

#endif  // LEETCODE_PROBLEMS_MOST_COMMON_WORD_H_
