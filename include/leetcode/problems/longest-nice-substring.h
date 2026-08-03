#ifndef LEETCODE_PROBLEMS_LONGEST_NICE_SUBSTRING_H__
#define LEETCODE_PROBLEMS_LONGEST_NICE_SUBSTRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1763 {

using Func = std::function<std::string(std::string)>;

class LongestNiceSubstringSolution : public SolutionBase<Func> {
 public:
  LongestNiceSubstringSolution();

  std::string longestNiceSubstring(std::string s);
};

}  // namespace problem_1763
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_NICE_SUBSTRING_H__
