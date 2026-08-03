#ifndef LEETCODE_PROBLEMS_2213_LONGEST_SUBSTRING_OF_ONE_REPEATING_CHARACTER_H
#define LEETCODE_PROBLEMS_2213_LONGEST_SUBSTRING_OF_ONE_REPEATING_CHARACTER_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2213 {

using Func = std::function<std::vector<int>(std::string, std::string, std::vector<int>&)>;

class LongestSubstringOfOneRepeatingCharacterSolution
    : public SolutionBase<Func> {
 public:
  LongestSubstringOfOneRepeatingCharacterSolution();

  std::vector<int> longestRepeating(std::string s, std::string queryCharacters,
                                    std::vector<int>& queryIndices);
};

}  // namespace problem_2213
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_2213_LONGEST_SUBSTRING_OF_ONE_REPEATING_CHARACTER_H
