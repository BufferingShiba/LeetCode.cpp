#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THE_LENGTH_OF_TWO_PALINDROMIC_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THE_LENGTH_OF_TWO_PALINDROMIC_SUBSEQUENCES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2002 {

using Func = std::function<int(std::string)>;

class MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution();

  int maxProduct(std::string s);
};

}  // namespace problem_2002
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THE_LENGTH_OF_TWO_PALINDROMIC_SUBSEQUENCES_H__
