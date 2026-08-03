#include "leetcode/problems/kth-smallest-amount-with-single-denomination-combination.h"
#include <algorithm>
#include <numeric>

namespace leetcode {
namespace problem_3116 {

static long long findKthSmallestImpl(std::vector<int>& coins, int k) {
    // Step 1: remove redundant coins (if a | b, b is redundant)
    std::sort(coins.begin(), coins.end());
    std::vector<int> essential;
    for (int c : coins) {
        bool redundant = false;
        for (int e : essential) {
            if (c % e == 0) {
                redundant = true;
                break;
            }
        }
        if (!redundant) essential.push_back(c);
    }

    int n = (int)essential.size();

    // Count numbers <= X that are divisible by at least one coin (inclusion-exclusion)
    auto count_le = [&](long long X) -> long long {
        long long total = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long lcm = 1;
            int bits = 0;
            bool overflow = false;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;
                    long long g = std::gcd(lcm, (long long)essential[i]);
                    // check if lcm / g * essential[i] > X
                    if (lcm / g > X / essential[i]) {
                        overflow = true;
                        break;
                    }
                    lcm = lcm / g * essential[i];
                }
            }
            if (overflow) continue;  // lcm > X, contributes 0
            long long cnt = X / lcm;
            if (bits % 2 == 1) {
                total += cnt;
            } else {
                total -= cnt;
            }
        }
        return total;
    };

    // Binary search: minimal X with count_le(X) >= k
    long long lo = 1, hi = (long long)k * essential[0];
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (count_le(mid) >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

KthSmallestAmountWithSingleDenominationCombinationSolution::
    KthSmallestAmountWithSingleDenominationCombinationSolution() {
    setMetaInfo({.id = 3116,
                 .title = "Kth Smallest Amount With Single Denomination Combination",
                 .url = "https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/"});
    registerStrategy({.name = "binary_search_inclusion_exclusion",
                      .expected = "Accepted",
                      .time_complexity = "O(2^n * log(k * min(coins)))",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Math", "Binary Search", "Bit Manipulation",
                               "Combinatorics", "Number Theory"}},
                     findKthSmallestImpl);
}

long long KthSmallestAmountWithSingleDenominationCombinationSolution::findKthSmallest(
    std::vector<int>& coins, int k) {
    return getSolution()(coins, k);
}

} // namespace problem_3116
} // namespace leetcode
