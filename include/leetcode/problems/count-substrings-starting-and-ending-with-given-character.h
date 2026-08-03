#ifndef LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_STARTING_AND_ENDING_WITH_GIVEN_CHARACTER_H
#define LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_STARTING_AND_ENDING_WITH_GIVEN_CHARACTER_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3084 {

using Func = std::function<long long(std::string, char)>;

class CountSubstringsStartingAndEndingWithGivenCharacterSolution : public SolutionBase<Func> {
 public:
  CountSubstringsStartingAndEndingWithGivenCharacterSolution();

  long long countSubstrings(std::string s, char c);
};

}  // namespace problem_3084
}  // namespace leetcode

#endif
