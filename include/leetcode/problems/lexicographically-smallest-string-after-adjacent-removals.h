#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_ADJACENT_REMOVALS_H__
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_ADJACENT_REMOVALS_H__

#include <string>
#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3563 {

using Func = std::function<std::string(std::string)>;

class LexicographicallySmallestStringAfterAdjacentRemovalsSolution : public SolutionBase<Func> {
 public:
  std::string lexicographicallySmallestString(std::string s);
  LexicographicallySmallestStringAfterAdjacentRemovalsSolution();
};

}  // namespace problem_3563
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_ADJACENT_REMOVALS_H__
