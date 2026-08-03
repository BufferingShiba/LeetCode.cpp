#ifndef LEETCODE_PROBLEMS_MOST_FREQUENT_EVEN_ELEMENT_H__
#define LEETCODE_PROBLEMS_MOST_FREQUENT_EVEN_ELEMENT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2404 {

using Func = std::function<int(std::vector<int>&)>;

class MostFrequentEvenElementSolution
    : public SolutionBase<Func> {
 public:
  MostFrequentEvenElementSolution();

  int mostFrequentEven(std::vector<int>& nums);
};

}  // namespace problem_2404
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOST_FREQUENT_EVEN_ELEMENT_H__
