#ifndef LEETCODE_PROBLEMS_BEST_POKER_HAND_H__
#define LEETCODE_PROBLEMS_BEST_POKER_HAND_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2347 {

using Func = std::function<std::string(std::vector<int>&, std::vector<char>&)>;

class BestPokerHandSolution : public SolutionBase<Func> {
 public:
  BestPokerHandSolution();
  std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits);
};

}  // namespace problem_2347
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BEST_POKER_HAND_H__
