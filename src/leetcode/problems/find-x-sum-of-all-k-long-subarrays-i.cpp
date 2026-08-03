#include "leetcode/problems/find-x-sum-of-all-k-long-subarrays-i.h"

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace leetcode::problem_3318 {

static std::vector<int> findXSumImpl(std::vector<int>& nums, int k, int x) {
    int n = static_cast<int>(nums.size());
    std::vector<int> answer;
    answer.reserve(n - k + 1);

    for (int i = 0; i <= n - k; ++i) {
        std::unordered_map<int, int> freq;
        for (int j = i; j < i + k; ++j) {
            freq[nums[j]]++;
        }

        std::vector<std::pair<int, int>> items;  // (value, freq)
        for (auto& [val, f] : freq) {
            items.emplace_back(val, f);
        }

        std::sort(items.begin(), items.end(),
                  [](const auto& a, const auto& b) {
                      if (a.second != b.second) return a.second > b.second;
                      return a.first > b.first;
                  });

        int sum = 0;
        int limit = std::min(x, static_cast<int>(items.size()));
        for (int t = 0; t < limit; ++t) {
            sum += items[t].first * items[t].second;
        }
        answer.push_back(sum);
    }

    return answer;
}

FindXSumOfAllKLongSubarraysISolution::FindXSumOfAllKLongSubarraysISolution() {
    setMetaInfo({.id = 3318,
                 .title = "Find X-Sum of All K-Long Subarrays I",
                 .url = "https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/"});
    registerStrategy(
        {.name = "Brute Force",
         .expected = "Accepted",
         .time_complexity = "O(n * k log k)",
         .space_complexity = "O(k)",
         .tags = {"Array", "Hash Table", "Sliding Window", "Sorting"}},
        findXSumImpl);
}

std::vector<int> FindXSumOfAllKLongSubarraysISolution::findXSum(std::vector<int>& nums, int k,
                                                                 int x) {
    return getSolution()(nums, k, x);
}

}  // namespace leetcode::problem_3318
