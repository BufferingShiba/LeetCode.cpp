#include "leetcode/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target.h"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2023 {
namespace {

// 哈希表计数：对每个 s，若 target 以 s 为前缀，剩余部分 r = target.substr(s.size())，
// 则 ans 累加 cnt[r]；若 s == r，减去自身（避免 i == j）。
int numOfPairsImpl(std::vector<std::string>& nums, std::string target) {
  std::unordered_map<std::string, int> cnt;
  for (const auto& s : nums) {
    ++cnt[s];
  }

  long long ans = 0;
  const std::string& t = target;
  for (const auto& s : nums) {
    if (s.size() > t.size() || t.compare(0, s.size(), s) != 0) {
      continue;
    }
    std::string r = t.substr(s.size());
    auto it = cnt.find(r);
    if (it != cnt.end()) {
      ans += it->second;
      if (s == r) {
        --ans;
      }
    }
  }
  return static_cast<int>(ans);
}

}  // namespace

NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution::
    NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution() {
  setMetaInfo({
      2023,
      "Number of Pairs of Strings With Concatenation Equal to Target",
      "https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/",
  });
  registerStrategy(
      {"hashmap", "Accepted", "O(n)", "O(n)", {"Hash Table", "String", "Counting"}},
      numOfPairsImpl);
}

int NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution::numOfPairs(
    std::vector<std::string>& nums, std::string target) {
  return getSolution()(nums, std::move(target));
}

}  // namespace problem_2023
}  // namespace leetcode
