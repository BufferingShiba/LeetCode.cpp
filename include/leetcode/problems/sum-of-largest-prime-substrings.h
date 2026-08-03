#ifndef LEETCODE_PROBLEMS_SUM_OF_LARGEST_PRIME_SUBSTRINGS_H_
#define LEETCODE_PROBLEMS_SUM_OF_LARGEST_PRIME_SUBSTRINGS_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3556 {

using Func = std::function<long long(std::string)>;

class SumOfLargestPrimeSubstringsSolution : public SolutionBase<Func> {
 public:
  SumOfLargestPrimeSubstringsSolution();

  long long sumOfLargestPrimes(std::string s);
};

}  // namespace problem_3556
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_LARGEST_PRIME_SUBSTRINGS_H_
