#ifndef LEETCODE_PROBLEMS_FIND_THE_CLOSEST_PALINDROME_H_
#define LEETCODE_PROBLEMS_FIND_THE_CLOSEST_PALINDROME_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_564 {

using Func = std::function<std::string(std::string)>;

class FindTheClosestPalindromeSolution : public SolutionBase<Func> {
 public:
  FindTheClosestPalindromeSolution() {
    setMetaInfo({.id = 564,
                 .title = "Find the Closest Palindrome",
                 .url = "https://leetcode.com/problems/find-the-closest-palindrome/"});
    registerStrategies();
  }

  std::string nearestPalindromic(std::string n);

 private:
  void registerStrategies();
};

}  // namespace problem_564
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_CLOSEST_PALINDROME_H_
