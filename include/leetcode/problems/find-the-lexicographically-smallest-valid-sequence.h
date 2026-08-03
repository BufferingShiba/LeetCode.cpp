#ifndef LEETCODE_PROBLEMS_FIND_THE_LEXICOGRAPHICALLY_SMALLEST_VALID_SEQUENCE_H__
#define LEETCODE_PROBLEMS_FIND_THE_LEXICOGRAPHICALLY_SMALLEST_VALID_SEQUENCE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3302 {

using Func = std::function<std::vector<int>(std::string, std::string)>;

class FindTheLexicographicallySmallestValidSequenceSolution
    : public SolutionBase<Func> {
 public:
  FindTheLexicographicallySmallestValidSequenceSolution();
  std::vector<int> validSequence(std::string word1, std::string word2);
};

}  // namespace leetcode::problem_3302

#endif  // LEETCODE_PROBLEMS_FIND_THE_LEXICOGRAPHICALLY_SMALLEST_VALID_SEQUENCE_H__
