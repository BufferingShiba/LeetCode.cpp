#ifndef LEETCODE_RANDOM_PICK_WITH_WEIGHT_H
#define LEETCODE_RANDOM_PICK_WITH_WEIGHT_H

#include <vector>

namespace leetcode::problem_528 {

class RandomPickWithWeightSolution {
 public:
  explicit RandomPickWithWeightSolution(std::vector<int>& w);
  int pickIndex();

 private:
  std::vector<int> prefix_;
  int total_;
};

}  // namespace leetcode::problem_528

#endif  // LEETCODE_RANDOM_PICK_WITH_WEIGHT_H
