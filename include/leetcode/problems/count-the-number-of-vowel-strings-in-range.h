#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_VOWEL_STRINGS_IN_RANGE_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_VOWEL_STRINGS_IN_RANGE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2586 {

using Func = std::function<int(std::vector<std::string>&, int, int)>;

class CountTheNumberOfVowelStringsInRangeSolution
    : public SolutionBase<Func> {
 public:
  CountTheNumberOfVowelStringsInRangeSolution();

  int vowelStrings(std::vector<std::string>& words, int left, int right);
};

}  // namespace problem_2586
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_VOWEL_STRINGS_IN_RANGE_H__
