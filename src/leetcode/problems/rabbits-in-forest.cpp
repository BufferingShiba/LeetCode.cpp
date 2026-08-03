#include <unordered_map>
#include <vector>

#include "leetcode/problems/rabbits-in-forest.h"

namespace leetcode {
namespace problem_781 {

namespace {

int numRabbitsImpl(std::vector<int>& answers) {
  std::unordered_map<int, int> cnt;
  for (int a : answers) {
    ++cnt[a];
  }
  int total = 0;
  for (const auto& entry : cnt) {
    int x = entry.first;      // 每组有 x+1 只兔子
    int c = entry.second;     // 报数 x 的兔子数
    int groups = (c + x) / (x + 1);  // ceil(c / (x+1))
    total += groups * (x + 1);
  }
  return total;
}

}  // namespace

int RabbitsInForestSolution::numRabbits(std::vector<int>& answers) {
  return getSolution()(answers);
}

RabbitsInForestSolution::RabbitsInForestSolution() {
  setMetaInfo({.id = 781,
               .title = "Rabbits in Forest",
               .url = "https://leetcode.com/problems/rabbits-in-forest/"});
  registerStrategy(
      {"greedy-counting", "Expected", "O(n)", "O(n)", {"Array", "Hash Table", "Math", "Greedy"}},
      numRabbitsImpl);
}

}  // namespace problem_781
}  // namespace leetcode
