#ifndef LEETCODE_PROBLEMS_TRIPLES_WITH_BITWISE_AND_EQUAL_TO_ZERO_H__
#define LEETCODE_PROBLEMS_TRIPLES_WITH_BITWISE_AND_EQUAL_TO_ZERO_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_982 {

using Func = std::function<int(std::vector<int>&)>;

class TriplesWithBitwiseAndEqualToZeroSolution
    : public SolutionBase<Func> {
 public:
  TriplesWithBitwiseAndEqualToZeroSolution();
  int countTriplets(std::vector<int>& nums);
};

}  // namespace problem_982
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TRIPLES_WITH_BITWISE_AND_EQUAL_TO_ZERO_H__
