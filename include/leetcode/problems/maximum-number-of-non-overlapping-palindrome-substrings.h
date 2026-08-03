#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_NON_OVERLAPPING_PALINDROME_SUBSTRINGS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_NON_OVERLAPPING_PALINDROME_SUBSTRINGS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2472 {

using Func = std::function<int(std::string, int)>;

class MaximumNumberOfNonOverlappingPalindromeSubstringsSolution : public SolutionBase<Func> {
public:
    MaximumNumberOfNonOverlappingPalindromeSubstringsSolution();
    int maxPalindromes(std::string s, int k);
};

}  // namespace problem_2472
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_NON_OVERLAPPING_PALINDROME_SUBSTRINGS_H__
