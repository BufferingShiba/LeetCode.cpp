#ifndef LEETCODE_PROBLEMS_CHECK_IF_THE_SENTENCE_IS_PANGRAM_H__
#define LEETCODE_PROBLEMS_CHECK_IF_THE_SENTENCE_IS_PANGRAM_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1832 {

using Func = std::function<bool(std::string)>;

class CheckIfTheSentenceIsPangramSolution : public SolutionBase<Func> {
 public:
  CheckIfTheSentenceIsPangramSolution();

  bool checkIfPangram(std::string sentence);
};

}  // namespace problem_1832
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_THE_SENTENCE_IS_PANGRAM_H__
