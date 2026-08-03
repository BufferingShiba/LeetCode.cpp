#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_APPLYING_OPERATIONS_H_
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_APPLYING_OPERATIONS_H_

#include <functional>
#include <string>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1625 {

using Func = std::function<std::string(std::string, int, int)>;

class LexicographicallySmallestStringAfterApplyingOperationsSolution
    : public SolutionBase<Func> {
 public:
  LexicographicallySmallestStringAfterApplyingOperationsSolution();

  std::string findLexSmallestString(std::string s, int a, int b);
};

}  // namespace problem_1625
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_APPLYING_OPERATIONS_H_
