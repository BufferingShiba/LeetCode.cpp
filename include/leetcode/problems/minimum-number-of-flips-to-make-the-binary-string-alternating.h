#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_THE_BINARY_STRING_ALTERNATING_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_THE_BINARY_STRING_ALTERNATING_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1888 {

class MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingSolution : public SolutionBase<std::function<int(std::string)>> {
 public:
  MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingSolution();

  int minFlips(std::string s);
};

}  // namespace problem_1888
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_THE_BINARY_STRING_ALTERNATING_H__
