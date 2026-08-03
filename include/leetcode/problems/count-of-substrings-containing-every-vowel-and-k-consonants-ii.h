#ifndef LEETCODE_PROBLEMS_COUNT_OF_SUBSTRINGS_CONTAINING_EVERY_VOWEL_AND_K_CONSONANTS_II_H_
#define LEETCODE_PROBLEMS_COUNT_OF_SUBSTRINGS_CONTAINING_EVERY_VOWEL_AND_K_CONSONANTS_II_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3306 {

using Func = std::function<long long(std::string, int)>;

class CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution : public SolutionBase<Func> {
 public:
  CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution();

  long long countOfSubstrings(std::string word, int k);
};

}  // namespace problem_3306
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_OF_SUBSTRINGS_CONTAINING_EVERY_VOWEL_AND_K_CONSONANTS_II_H_
