#ifndef LEETCODE_PROBLEMS_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H_
#define LEETCODE_PROBLEMS_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2414 {

using Func = std::function<int(std::string)>;

class LengthOfTheLongestAlphabeticalContinuousSubstringSolution : public SolutionBase<Func> {
 public:
  LengthOfTheLongestAlphabeticalContinuousSubstringSolution();

  int longestContinuousSubstring(std::string s);
};

}  // namespace problem_2414
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H_
