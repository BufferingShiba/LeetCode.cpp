#ifndef LEETCODE_PROBLEMS_STRING_MATCHING_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_STRING_MATCHING_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1408 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class StringMatchingInAnArraySolution
    : public SolutionBase<Func> {
 public:
  StringMatchingInAnArraySolution();

  std::vector<std::string> stringMatching(std::vector<std::string>& words);
};

}  // namespace problem_1408
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_STRING_MATCHING_IN_AN_ARRAY_H__
