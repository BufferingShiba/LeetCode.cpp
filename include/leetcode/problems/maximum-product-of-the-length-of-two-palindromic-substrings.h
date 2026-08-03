#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THE_LENGTH_OF_TWO_PALINDROMIC_SUBSTRINGS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THE_LENGTH_OF_TWO_PALINDROMIC_SUBSTRINGS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

namespace leetcode {
namespace problem_1960 {

using Func = std::function<long long(std::string)>;

class MaximumProductOfTheLengthOfTwoPalindromicSubstringsSolution
    : public SolutionBase<Func> {
 public:
  MaximumProductOfTheLengthOfTwoPalindromicSubstringsSolution() {
    setMetaInfo({.id = 1960,
                 .title = "Maximum Product of the Length of Two Palindromic "
                          "Substrings",
                 .url = "https://leetcode.com/problems/maximum-product-of-the-"
                        "length-of-two-palindromic-substrings/"});
    registerStrategy(
        {.name = "ManacherPrefixSuffixMax",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(n)",
         .tags = {"Manacher", "Two Pointers", "String"}},
        &maxProductImpl);
  }

  long long maxProduct(std::string s) { return getSolution()(std::move(s)); }

 private:
  static long long maxProductImpl(std::string s) {
    const int n = static_cast<int>(s.size());
    if (n < 2) return 0;

    // Manacher: d[i] = radius of max odd palindrome centered at i (includes
    // center). Palindrome is s[i-d[i]+1 .. i+d[i]-1], length 2*d[i]-1.
    std::vector<int> d(n, 1);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
      int k = (i >= r) ? 1 : std::min(d[l + r - i], r - i + 1);
      while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
      d[i] = k;
      if (i + k - 1 > r) {
        l = i - k + 1;
        r = i + k - 1;
      }
    }

    // bestEnd[t] = longest odd palindrome ending AT t (left section).
    std::vector<long long> bestEnd(n, 0);
    for (int i = 0; i < n; ++i) {
      long long len = 2LL * d[i] - 1;
      int end = i + d[i] - 1;
      if (len > bestEnd[end]) bestEnd[end] = len;
    }
    for (int i = n - 2; i >= 0; --i) {
      bestEnd[i] = std::max(bestEnd[i], bestEnd[i + 1] - 2);
    }

    // bestStart[t] = longest odd palindrome starting AT t (right section).
    std::vector<long long> bestStart(n, 0);
    for (int i = 0; i < n; ++i) {
      long long len = 2LL * d[i] - 1;
      int start = i - d[i] + 1;
      if (len > bestStart[start]) bestStart[start] = len;
    }
    for (int i = 1; i < n; ++i) {
      bestStart[i] = std::max(bestStart[i], bestStart[i - 1] - 2);
    }

    // prefix max over end positions [0..cut].
    std::vector<long long> pref(n, 0);
    pref[0] = bestEnd[0];
    for (int i = 1; i < n; ++i) {
      pref[i] = std::max(pref[i - 1], bestEnd[i]);
    }

    // suffix max over start positions [cut..n-1].
    std::vector<long long> suf(n, 0);
    suf[n - 1] = bestStart[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      suf[i] = std::max(suf[i + 1], bestStart[i]);
    }

    long long ans = 0;
    for (int cut = 0; cut + 1 < n; ++cut) {
      ans = std::max(ans, pref[cut] * suf[cut + 1]);
    }
    return ans;
  }
};

}  // namespace problem_1960
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THE_LENGTH_OF_TWO_PALINDROMIC_SUBSTRINGS_H__
