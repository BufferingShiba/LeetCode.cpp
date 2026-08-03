#ifndef LEETCODE_PROBLEMS_FIND_AND_REPLACE_PATTERN_H__
#define LEETCODE_PROBLEMS_FIND_AND_REPLACE_PATTERN_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_890 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&, std::string)>;

class FindAndReplacePatternSolution : public SolutionBase<Func> {
 public:
  FindAndReplacePatternSolution();

  std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words,
                                                  std::string pattern);
};

}  // namespace problem_890
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_AND_REPLACE_PATTERN_H__
