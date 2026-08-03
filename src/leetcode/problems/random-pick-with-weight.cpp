#include "leetcode/problems/random-pick-with-weight.h"

#include <algorithm>
#include <random>

namespace leetcode::problem_528 {

RandomPickWithWeightSolution::RandomPickWithWeightSolution(std::vector<int>& w) {
  prefix_.resize(w.size());
  total_ = 0;
  for (std::size_t i = 0; i < w.size(); ++i) {
    total_ += w[i];
    prefix_[i] = total_;
  }
}

int RandomPickWithWeightSolution::pickIndex() {
  static std::mt19937 gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0, total_ - 1);
  int r = dist(gen);  // random in [0, total_)
  // smallest i with prefix_[i] > r  ->  index i is chosen with probability w[i]/total_
  return static_cast<int>(
      std::upper_bound(prefix_.begin(), prefix_.end(), r) - prefix_.begin());
}

}  // namespace leetcode::problem_528
