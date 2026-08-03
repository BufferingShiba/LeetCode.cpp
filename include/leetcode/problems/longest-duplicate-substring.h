#ifndef LEETCODE_PROBLEMS_LONGEST_DUPLICATE_SUBSTRING_H_
#define LEETCODE_PROBLEMS_LONGEST_DUPLICATE_SUBSTRING_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1044 {

using Func = std::function<std::string(std::string)>;

class LongestDuplicateSubstringSolution : public SolutionBase<Func> {
 public:
  LongestDuplicateSubstringSolution();

  std::string longestDupSubstring(std::string s);
};

}  // namespace problem_1044
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_DUPLICATE_SUBSTRING_H_
