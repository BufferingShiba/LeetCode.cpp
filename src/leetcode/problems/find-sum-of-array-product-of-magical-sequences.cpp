#include "leetcode/problems/find-sum-of-array-product-of-magical-sequences.h"

namespace leetcode {
namespace problem_3539 {

namespace {

constexpr int MOD = 1000000007;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int magicalSumImpl(int m, int k, std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (k > m) return 0;

    // factorials and inverse factorials
    std::vector<long long> fact(m + 1), inv_fact(m + 1);
    fact[0] = 1;
    for (int i = 1; i <= m; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[m] = modPow(fact[m], MOD - 2, MOD);
    for (int i = m - 1; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

    // popcount table for 0..m
    std::vector<int> popcount(m + 1, 0);
    for (int i = 1; i <= m; ++i) popcount[i] = popcount[i >> 1] + (i & 1);

    // factor[pos][c] = nums[pos]^c * inv_fact[c] % MOD
    std::vector<std::vector<long long>> factor(n, std::vector<long long>(m + 1, 1));
    for (int pos = 0; pos < n; ++pos) {
        long long pow_val = 1;
        for (int c = 0; c <= m; ++c) {
            factor[pos][c] = pow_val * inv_fact[c] % MOD;
            pow_val = pow_val * nums[pos] % MOD;
        }
    }

    // dp[used][carry][pop]
    std::vector<std::vector<std::vector<long long>>> dp(
        m + 1,
        std::vector<std::vector<long long>>(
            m + 1, std::vector<long long>(k + 1, 0)));
    dp[0][0][0] = 1;

    for (int pos = 0; pos < n; ++pos) {
        std::vector<std::vector<std::vector<long long>>> ndp(
            m + 1,
            std::vector<std::vector<long long>>(
                m + 1, std::vector<long long>(k + 1, 0)));
        for (int used = 0; used <= m; ++used) {
            for (int carry = 0; carry <= m; ++carry) {
                for (int pop = 0; pop <= k; ++pop) {
                    long long cur = dp[used][carry][pop];
                    if (cur == 0) continue;
                    int max_c = m - used;
                    for (int c = 0; c <= max_c; ++c) {
                        int total = c + carry;
                        int new_carry = total >> 1;
                        int new_pop = pop + (total & 1);
                        if (new_pop > k) continue;
                        ndp[used + c][new_carry][new_pop] =
                            (ndp[used + c][new_carry][new_pop] +
                             cur * factor[pos][c]) %
                            MOD;
                    }
                }
            }
        }
        dp = std::move(ndp);
    }

    long long ans = 0;
    for (int carry = 0; carry <= m; ++carry) {
        for (int pop = 0; pop <= k; ++pop) {
            if (pop + popcount[carry] == k) {
                ans = (ans + dp[m][carry][pop]) % MOD;
            }
        }
    }
    ans = ans * fact[m] % MOD;
    return static_cast<int>(ans);
}

}  // namespace

FindSumOfArrayProductOfMagicalSequencesSolution::
    FindSumOfArrayProductOfMagicalSequencesSolution() {
    setMetaInfo({.id = 3539,
                 .title = "Find Sum of Array Product of Magical Sequences",
                 .url = "https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/"});
    registerStrategy(
        {.name = "DP",
         .expected = "Accepted",
         .time_complexity = "O(n * m^2 * k)",
         .space_complexity = "O(m^2 * k)",
         .tags = {"Array", "Math", "Dynamic Programming", "Bit Manipulation",
                  "Combinatorics", "Bitmask"}},
        magicalSumImpl);
}

int FindSumOfArrayProductOfMagicalSequencesSolution::magicalSum(
    int m, int k, std::vector<int>& nums) {
    return getSolution()(m, k, nums);
}

}  // namespace problem_3539
}  // namespace leetcode
