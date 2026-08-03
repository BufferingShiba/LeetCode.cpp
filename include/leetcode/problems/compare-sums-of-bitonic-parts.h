#ifndef LEETCODE_PROBLEMS_COMPARE_SUMS_OF_BITONIC_PARTS_H__
#define LEETCODE_PROBLEMS_COMPARE_SUMS_OF_BITONIC_PARTS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3909 {

using Func = std::function<int(std::vector<int>&)>;

class CompareSumsOfBitonicPartsSolution : public SolutionBase<Func> {
 public:
  CompareSumsOfBitonicPartsSolution();

  int compareBitonicSums(std::vector<int>& nums);
};

}  // namespace problem_3909
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COMPARE_SUMS_OF_BITONIC_PARTS_H__
