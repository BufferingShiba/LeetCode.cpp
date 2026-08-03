#include "leetcode/problems/random-pick-index.h"

#include <cstddef>
#include <random>

namespace leetcode::problem_398 {

RandomPickIndex::RandomPickIndex(const std::vector<int>& nums) : gen_(std::random_device{}()) {
  for (std::size_t i = 0; i < nums.size(); ++i) {
    index_[nums[i]].push_back(static_cast<int>(i));
  }
}

int RandomPickIndex::pick(int target) {
  const auto& indices = index_.at(target);
  std::uniform_int_distribution<std::size_t> dist(0, indices.size() - 1);
  return indices[dist(gen_)];
}

}  // namespace leetcode::problem_398
