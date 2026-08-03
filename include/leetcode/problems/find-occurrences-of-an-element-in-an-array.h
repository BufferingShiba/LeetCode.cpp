#ifndef LEETCODE_PROBLEMS_FIND_OCCURRENCES_OF_AN_ELEMENT_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_OCCURRENCES_OF_AN_ELEMENT_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3159 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&, int)>;

class FindOccurrencesOfAnElementInAnArraySolution
    : public SolutionBase<Func> {
 public:
  FindOccurrencesOfAnElementInAnArraySolution();

  std::vector<int> occurrencesOfElement(std::vector<int>& nums,
                                        std::vector<int>& queries, int x);
};

}  // namespace leetcode::problem_3159

#endif  // LEETCODE_PROBLEMS_FIND_OCCURRENCES_OF_AN_ELEMENT_IN_AN_ARRAY_H__
