#include "leetcode/problems/find-k-pairs-with-smallest-sums.h"

#include <queue>
#include <tuple>
#include <vector>

namespace leetcode {
namespace problem_373 {

namespace {

std::vector<std::vector<int>> kSmallestPairsImpl(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    int m = static_cast<int>(nums1.size());
    int n = static_cast<int>(nums2.size());
    std::vector<std::vector<int>> result;
    result.reserve(k);

    auto cmp = [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<0>(a) > std::get<0>(b);
    };
    std::priority_queue<
        std::tuple<int, int, int>,
        std::vector<std::tuple<int, int, int>>,
        decltype(cmp)> pq(cmp);

    // Initialize heap with the smallest pair from each row:
    // (nums1[i] + nums2[0], i, 0) for i = 0 .. min(m, k)-1
    for (int i = 0; i < m && i < k; ++i) {
        pq.emplace(nums1[i] + nums2[0], i, 0);
    }

    while (k-- > 0 && !pq.empty()) {
        auto [sum, i, j] = pq.top();
        pq.pop();
        result.push_back({nums1[i], nums2[j]});
        if (j + 1 < n) {
            pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
        }
    }

    return result;
}

} // anonymous namespace

FindKPairsWithSmallestSumsSolution::FindKPairsWithSmallestSumsSolution() {
    setMetaInfo({.id = 373, .title = "Find K Pairs with Smallest Sums", .url = "https://leetcode.com/problems/find-k-pairs-with-smallest-sums/"});
    registerStrategy(
        {.name = "MinHeap",
         .expected = "Accepted",
         .time_complexity = "O(k log min(m, k))",
         .space_complexity = "O(min(m, k))",
         .tags = {"Array", "Heap (Priority Queue)"}},
        kSmallestPairsImpl);
    setDefaultStrategy();
}

std::vector<std::vector<int>> FindKPairsWithSmallestSumsSolution::kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    return getSolution()(nums1, nums2, k);
}

} // namespace problem_373
} // namespace leetcode
