#ifndef LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_WITH_K_FREQUENCY_CHARACTERS_I_H__
#define LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_WITH_K_FREQUENCY_CHARACTERS_I_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3325 {

using Func = std::function<int(std::string, int)>;

class CountSubstringsWithKFrequencyCharactersISolution
    : public SolutionBase<Func> {
 public:
  CountSubstringsWithKFrequencyCharactersISolution();

  int numberOfSubstrings(std::string s, int k);
};

}  // namespace problem_3325
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_WITH_K_FREQUENCY_CHARACTERS_I_H__
