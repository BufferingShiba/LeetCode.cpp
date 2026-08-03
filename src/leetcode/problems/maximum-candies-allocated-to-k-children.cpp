#include "leetcode/problems/maximum-candies-allocated-to-k-children.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_2226 {

namespace {

bool canAllocate(const std::vector<int>& candies, long long k, long long mid) {
    if (mid == 0) return true;
    long long count = 0;
    for (int c : candies) {
        count += static_cast<long long>(c) / mid;
        if (count >= k) return true;
    }
    return count >= k;
}

int maximumCandiesImpl(std::vector<int>& candies, long long k) {
    long long low = 0;
    long long high = *std::max_element(candies.begin(), candies.end());
    long long result = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canAllocate(candies, k, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return static_cast<int>(result);
}

}  // namespace

int MaximumCandiesAllocatedToKChildrenSolution::maximumCandies(
    std::vector<int>& candies, long long k) {
    return getSolution()(candies, k);
}

MaximumCandiesAllocatedToKChildrenSolution::MaximumCandiesAllocatedToKChildrenSolution() {
    setMetaInfo(
        {.id = 2226,
         .title = "Maximum Candies Allocated to K Children",
         .url = "https://leetcode.com/problems/maximum-candies-allocated-to-k-children/"});
    registerStrategy(
        {.name = "BinarySearch",
         .expected = "Accepted",
         .time_complexity = "O(n log max(candies))",
         .space_complexity = "O(1)",
         .tags = {"Array", "Binary Search"}},
        maximumCandiesImpl);
}

}  // namespace leetcode::problem_2226
