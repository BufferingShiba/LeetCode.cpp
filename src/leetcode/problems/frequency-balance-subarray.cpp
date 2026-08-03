#include "leetcode/problems/frequency-balance-subarray.h"

#include <map>
#include <unordered_map>

namespace leetcode {
namespace problem_3960 {
namespace {

// Enumerate all subarrays. For each start l, extend right endpoint r one by one
// while maintaining per-value counts and a frequency->(number of distinct values
// having that frequency) map. A subarray is frequency-balanced iff:
//   - only one distinct value exists, OR
//   - minFreq * 2 == maxFreq and every distinct value's frequency is exactly
//     minFreq or maxFreq (guaranteed by mx == 2*mn together with no in-between
//     distinct frequencies checked via freqCount).
int longestFrequencyBalanceSubarray(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int best = 1;

  for (int l = 0; l < n; ++l) {
    std::unordered_map<int, int> count;  // value -> current frequency
    std::map<int, int> freqCount;        // frequency -> how many distinct values
    int distinct = 0;

    for (int r = l; r < n; ++r) {
      const int v = nums[r];
      int oldF = 0;
      auto it = count.find(v);
      if (it != count.end()) {
        oldF = it->second;
      } else {
        ++distinct;
      }

      if (oldF > 0) {
        auto fc = freqCount.find(oldF);
        if (--(fc->second) == 0) {
          freqCount.erase(fc);
        }
      }
      const int newF = oldF + 1;
      count[v] = newF;
      ++freqCount[newF];

      bool balanced = false;
      if (distinct == 1) {
        balanced = true;
      } else {
        const int mn = freqCount.begin()->first;
        const int mx = freqCount.rbegin()->first;
        long long sum = 0;
        for (const auto& kv : freqCount) {
          if (kv.first == mn || kv.first == mx) {
            sum += kv.second;
          }
        }
        if (mx == 2 * mn && sum == static_cast<long long>(distinct)) {
          balanced = true;
        }
      }

      if (balanced && (r - l + 1) > best) {
        best = r - l + 1;
      }
    }
  }

  return best;
}

}  // namespace

FrequencyBalanceSubarraySolution::FrequencyBalanceSubarraySolution() {
  setMetaInfo({.id = 3960,
               .title = "Frequency Balance Subarray",
               .url = "https://leetcode.com/problems/frequency-balance-subarray/"});
  registerStrategy(
      {.name = "enumerate-all-subarrays",
       .expected = "Accepted",
       .time_complexity = "O(n^2 log n)",
       .space_complexity = "O(n)",
       .tags = {"array", "hash-table"},
       .notes = "For each start index, extend right endpoint maintaining per-value counts and a freq->count map; balanced iff single distinct or mx==2*mn with all freqs in {mn,mx}."},
      longestFrequencyBalanceSubarray);
}

int FrequencyBalanceSubarraySolution::getLength(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3960
}  // namespace leetcode
