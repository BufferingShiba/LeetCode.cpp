#ifndef LEETCODE_PROBLEMS_UNIQUE_LENGTH_3_PALINDROMIC_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_UNIQUE_LENGTH_3_PALINDROMIC_SUBSEQUENCES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1930 {

using Func = std::function<int(std::string)>;

class UniqueLength3PalindromicSubsequencesSolution : public SolutionBase<Func> {
public:
    UniqueLength3PalindromicSubsequencesSolution();
    int countPalindromicSubsequence(std::string s);
};

}  // namespace problem_1930
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNIQUE_LENGTH_3_PALINDROMIC_SUBSEQUENCES_H__
