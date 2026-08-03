#ifndef LEETCODE_PROBLEMS_COUNT_VOWEL_SUBSTRINGS_OF_A_STRING_H_
#define LEETCODE_PROBLEMS_COUNT_VOWEL_SUBSTRINGS_OF_A_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2062 {

using Func = std::function<int(std::string)>;

class CountVowelSubstringsOfAStringSolution
    : public SolutionBase<Func> {
 public:
  CountVowelSubstringsOfAStringSolution();

  int countVowelSubstrings(std::string word);
};

}  // namespace problem_2062
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_VOWEL_SUBSTRINGS_OF_A_STRING_H_
