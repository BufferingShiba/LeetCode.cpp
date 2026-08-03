#include "leetcode/problems/minimum-number-of-moves-to-make-palindrome.h"

namespace leetcode::problem_2193 {

static int minMovesToMakePalindromeImpl(std::string s) {
    int n = static_cast<int>(s.size());
    int ans = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        // Find the rightmost character matching s[left]
        int k = right;
        while (k > left && s[k] != s[left]) {
            k--;
        }

        if (k == left) {
            // s[left] is the character that appears an odd number of times.
            // It will eventually become the middle character. Swap it one step
            // towards the right and retry without advancing pointers.
            std::swap(s[left], s[left + 1]);
            ans++;
        } else {
            // Move s[k] to position 'right' by adjacent swaps.
            for (int p = k; p < right; ++p) {
                std::swap(s[p], s[p + 1]);
                ans++;
            }
            left++;
            right--;
        }
    }

    return ans;
}

MinimumNumberOfMovesToMakePalindromeSolution::MinimumNumberOfMovesToMakePalindromeSolution() {
    setMetaInfo({.id = 2193,
                 .title = "Minimum Number of Moves to Make Palindrome",
                 .url = "https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/"});
    registerStrategy({.name = "Greedy Two Pointers",
                      .expected = "Accepted",
                      .time_complexity = "O(n^2)",
                      .space_complexity = "O(n)",
                      .tags = {"Two Pointers", "String", "Greedy"}},
                     minMovesToMakePalindromeImpl);
}

int MinimumNumberOfMovesToMakePalindromeSolution::minMovesToMakePalindrome(std::string s) {
    return getSolution()(s);
}

}  // namespace leetcode::problem_2193
