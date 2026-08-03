#include "leetcode/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_3825 {

static int longestSubsequenceImpl(std::vector<int>& nums) {
    int ans = 0;
    int n = static_cast<int>(nums.size());
    std::vector<int> tails;
    tails.reserve(n);

    for (int bit = 0; bit < 30; ++bit) {
        tails.clear();
        for (int num : nums) {
            if ((num >> bit) & 1) {
                auto it = std::lower_bound(tails.begin(), tails.end(), num);
                if (it == tails.end()) {
                    tails.push_back(num);
                } else {
                    *it = num;
                }
            }
        }
        ans = std::max(ans, static_cast<int>(tails.size()));
    }
    return ans;
}

LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution::
    LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution() {
    setMetaInfo(
        {3825,
         "Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND",
         "https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/"});
    registerStrategy(
        {"bitwise-lis",
         "Accepted",
         "O(30 * n log n)",
         "O(n)",
         {"Array", "Binary Search", "Bit Manipulation", "Enumeration"},
         ""},
        longestSubsequenceImpl);
}

int LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution::longestSubsequence(
    std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace leetcode::problem_3825
