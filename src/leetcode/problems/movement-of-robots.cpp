#include "leetcode/problems/movement-of-robots.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2731 {
namespace {

const long long kMod = 1000000007LL;

// 碰撞后交换方向等价于彼此穿过身体，最终各机器人位置集合不变（忽略身份）。
// 因此 d 秒后每个机器人的位置为 nums[i] + (s[i]=='R' ? d : -d)。
// 对最终位置排序后，对所有 i<j 求和 (pos[j]-pos[i])：
//   pos[i] 作为负项出现 (n-1-i) 次，作为正项出现 i 次，
//   故系数 = i - (n-1-i) = 2i - (n-1)。
// 总和对 1e9+7 取模。
int sumDistanceImpl(std::vector<int>& nums, std::string& s, int d) {
  const int n = static_cast<int>(nums.size());
  std::vector<long long> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[i] = static_cast<long long>(nums[i]) +
             (s[i] == 'R' ? static_cast<long long>(d)
                          : -static_cast<long long>(d));
  }
  std::sort(pos.begin(), pos.end());

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    long long coeff = static_cast<long long>(2 * i) - (n - 1);
    long long term = ((pos[i] % kMod + kMod) % kMod) *
                     ((coeff % kMod + kMod) % kMod) % kMod;
    sum = (sum + term) % kMod;
  }
  return static_cast<int>(sum);
}

}  // namespace

MovementOfRobotsSolution::MovementOfRobotsSolution() {
  setMetaInfo({.id = 2731,
               .title = "Movement of Robots",
               .url = "https://leetcode.com/problems/movement-of-robots/"});
  registerStrategy(
      {.name = "Sort+PrefixCoefficient",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting", "Brainteaser"},
       .notes = "Collisions are equivalent to robots passing through each other."},
      sumDistanceImpl);
}

int MovementOfRobotsSolution::sumDistance(std::vector<int>& nums,
                                          std::string& s, int d) {
  return getSolution()(nums, s, d);
}

}  // namespace problem_2731
}  // namespace leetcode
