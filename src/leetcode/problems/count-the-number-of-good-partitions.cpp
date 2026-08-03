#include "leetcode/problems/count-the-number-of-good-partitions.h"

#include <unordered_map>

namespace leetcode {
namespace problem_2963 {

namespace {

const long long kMod = 1000000007LL;

long long ModPow(long long base, long long exp, long long mod) {
  long long result = 1LL;
  base %= mod;
  while (exp > 0) {
    if (exp & 1LL) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int numberOfGoodPartitionsImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> last_pos;
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    last_pos[nums[i]] = i;
  }

  // Merge required blocks. Each cut inside a block would split the same number
  // into two subarrays, which is forbidden. A block ends at index maxR.
  int blocks = 0;
  int max_end = 0;
  for (int i = 0; i < n; ++i) {
    max_end = std::max(max_end, last_pos[nums[i]]);
    if (i == max_end) {
      ++blocks;
    }
  }

  // With k required blocks, there are k-1 free cuts between them; each cut is
  // either present or absent, giving 2^(k-1) valid partitions.
  const long long result = ModPow(2LL, static_cast<long long>(blocks - 1), kMod);
  return static_cast<int>(result);
}

}  // namespace

CountTheNumberOfGoodPartitionsSolution::CountTheNumberOfGoodPartitionsSolution() {
  setMetaInfo({.id = 2963,
               .title = "Count the Number of Good Partitions",
               .url = "https://leetcode.com/problems/count-the-number-of-good-partitions/"});
  registerStrategy(
      {"Greedy block merging + fast pow", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table", "Math", "Combinatorics"}},
      numberOfGoodPartitionsImpl);
}

int CountTheNumberOfGoodPartitionsSolution::numberOfGoodPartitions(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2963
}  // namespace leetcode
