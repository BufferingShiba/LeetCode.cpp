#ifndef LEETCODE_PROBLEMS_FRUITS_INTO_BASKETS_II_H__
#define LEETCODE_PROBLEMS_FRUITS_INTO_BASKETS_II_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3477 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class FruitsIntoBasketsIiSolution : public SolutionBase<Func> {
 public:
  FruitsIntoBasketsIiSolution();

  int numOfUnplacedFruits(std::vector<int>& fruits,
                          std::vector<int>& baskets);
};

}  // namespace problem_3477
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FRUITS_INTO_BASKETS_II_H__
