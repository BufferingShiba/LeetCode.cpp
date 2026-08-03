#ifndef LEETCODE_PROBLEMS_RANDOM_PICK_INDEX_H_
#define LEETCODE_PROBLEMS_RANDOM_PICK_INDEX_H_

#include <random>
#include <unordered_map>
#include <vector>

namespace leetcode::problem_398 {

class RandomPickIndex {
 public:
  explicit RandomPickIndex(const std::vector<int>& nums);

  int pick(int target);

 private:
  // value -> all indices where nums[i] == value
  std::unordered_map<int, std::vector<int>> index_;
  std::mt19937 gen_;
};

}  // namespace leetcode::problem_398

#endif  // LEETCODE_PROBLEMS_RANDOM_PICK_INDEX_H_
