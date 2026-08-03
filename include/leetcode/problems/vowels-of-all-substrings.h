#ifndef LEETCODE_PROBLEMS_VOWELS_OF_ALL_SUBSTRINGS_H__
#define LEETCODE_PROBLEMS_VOWELS_OF_ALL_SUBSTRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2063 {

using Func = std::function<long long(const std::string&)>;

class VowelsOfAllSubstringsSolution
    : public SolutionBase<Func> {
 public:
  VowelsOfAllSubstringsSolution();

  long long countVowels(const std::string& word);
};

}  // namespace leetcode::problem_2063

#endif  // LEETCODE_PROBLEMS_VOWELS_OF_ALL_SUBSTRINGS_H__
