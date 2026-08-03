#ifndef LEETCODE_PROBLEMS_LENGTH_OF_THE_LONGEST_VALID_SUBSTRING_H_
#define LEETCODE_PROBLEMS_LENGTH_OF_THE_LONGEST_VALID_SUBSTRING_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2781 {

using Func = std::function<int(std::string, std::vector<std::string>&)>;

class LengthOfTheLongestValidSubstringSolution : public SolutionBase<Func> {
 public:
  LengthOfTheLongestValidSubstringSolution();

  int longestValidSubstring(std::string word, std::vector<std::string>& forbidden);
};

}  // namespace problem_2781
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LENGTH_OF_THE_LONGEST_VALID_SUBSTRING_H_
