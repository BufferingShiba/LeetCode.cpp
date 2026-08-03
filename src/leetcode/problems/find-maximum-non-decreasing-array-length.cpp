#include "leetcode/problems/find-maximum-non-decreasing-array-length.h"

#include <deque>
#include <vector>

namespace leetcode {
namespace problem_2945 {

static int findMaximumLengthImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n == 0) return 0;

    // prefix[k] = sum of nums[0..k-1]
    std::vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    std::vector<int> dp(n, 0);
    std::vector<long long> last(n, 0);  // last segment sum in optimal partition
    std::vector<long long> F(n, 0);     // F[j] = prefix[j+1] + last[j]

    std::deque<int> dq;
    dq.push_back(-1);  // dummy index: dp[-1]=0, prefix[0]=0, last=0, F=0

    for (int i = 0; i < n; ++i) {
        long long Pi = prefix[i + 1];

        // Pop front while the second element also satisfies F ≤ Pi.
        // The second element is further right, thus has ≥ dp and is better.
        while (dq.size() >= 2) {
            int second = dq[1];
            long long F_second = (second == -1) ? 0 : F[second];
            if (F_second <= Pi) {
                dq.pop_front();
            } else {
                break;
            }
        }

        int j = dq.front();
        long long Pj = (j == -1) ? 0 : prefix[j + 1];

        dp[i] = (j == -1 ? 0 : dp[j]) + 1;
        last[i] = Pi - Pj;
        F[i] = Pi + last[i];  // = 2*Pi - Pj

        // Maintain deque monotonicity: remove dominated elements from back.
        // If F[back] >= F[i], then back is further left and has ≤ dp,
        // but is harder (or equally hard) to satisfy — dominated by i.
        while (!dq.empty()) {
            int back = dq.back();
            long long F_back = (back == -1) ? 0 : F[back];
            if (F_back >= F[i]) {
                dq.pop_back();
            } else {
                break;
            }
        }
        dq.push_back(i);
    }

    return dp[n - 1];
}

FindMaximumNonDecreasingArrayLengthSolution::FindMaximumNonDecreasingArrayLengthSolution() {
    setMetaInfo({.id = 2945,
                 .title = "Find Maximum Non-decreasing Array Length",
                 .url = "https://leetcode.com/problems/find-maximum-non-decreasing-array-length/"});
    registerStrategy({.name = "MonotonicQueue",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Dynamic Programming", "Monotonic Queue", "Prefix Sum"}},
                     findMaximumLengthImpl);
}

int FindMaximumNonDecreasingArrayLengthSolution::findMaximumLength(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_2945
}  // namespace leetcode
