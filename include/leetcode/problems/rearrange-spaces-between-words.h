#ifndef LEETCODE_PROBLEMS_REARRANGE_SPACES_BETWEEN_WORDS_H_
#define LEETCODE_PROBLEMS_REARRANGE_SPACES_BETWEEN_WORDS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1592 {

using Func = std::function<std::string(std::string)>;

class RearrangeSpacesBetweenWordsSolution : public SolutionBase<Func> {
 public:
  RearrangeSpacesBetweenWordsSolution();

  std::string reorderSpaces(std::string text);
};

}  // namespace problem_1592
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REARRANGE_SPACES_BETWEEN_WORDS_H_
