#ifndef LEETCODE_PROBLEMS_NUMBER_OF_FLOWERS_IN_FULL_BLOOM_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_FLOWERS_IN_FULL_BLOOM_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2251 {

using Func =
    std::function<std::vector<int>(std::vector<std::vector<int>>&,
                                   std::vector<int>&)>;

class NumberOfFlowersInFullBloomSolution
    : public SolutionBase<Func> {
 public:
  NumberOfFlowersInFullBloomSolution();

  std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers,
                                    std::vector<int>& people);
};

}  // namespace problem_2251
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_FLOWERS_IN_FULL_BLOOM_H__
