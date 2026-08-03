#ifndef LEETCODE_PROBLEMS_LENGTH_OF_LAST_WORD_H_
#define LEETCODE_PROBLEMS_LENGTH_OF_LAST_WORD_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_58 {

using Func = std::function<int(std::string)>;

class LengthOfLastWordSolution : public SolutionBase<Func> {
 public:
  LengthOfLastWordSolution();

  int lengthOfLastWord(std::string s);
};

}  // namespace problem_58
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LENGTH_OF_LAST_WORD_H_
