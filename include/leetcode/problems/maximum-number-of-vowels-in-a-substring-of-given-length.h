#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_VOWELS_IN_A_SUBSTRING_OF_GIVEN_LENGTH_H_
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_VOWELS_IN_A_SUBSTRING_OF_GIVEN_LENGTH_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1456 {

using Func = std::function<int(std::string, int)>;

class MaximumNumberOfVowelsInASubstringOfGivenLengthSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfVowelsInASubstringOfGivenLengthSolution();

  int maxVowels(std::string s, int k);
};

}  // namespace problem_1456
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_VOWELS_IN_A_SUBSTRING_OF_GIVEN_LENGTH_H_
