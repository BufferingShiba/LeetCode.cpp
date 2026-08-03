#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_BEAUTIFUL_STRING_H_
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_BEAUTIFUL_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2663 {

using Func = std::function<std::string(std::string, int)>;

class LexicographicallySmallestBeautifulStringSolution
    : public SolutionBase<Func> {
 public:
  LexicographicallySmallestBeautifulStringSolution();

  std::string smallestBeautifulString(std::string s, int k);
};

}  // namespace problem_2663
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_BEAUTIFUL_STRING_H_
