#include "leetcode/problems/count-numbers-with-non-decreasing-digits.h"

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

namespace leetcode {
namespace problem_3519 {

namespace {

constexpr int MOD = 1'000'000'007;

// Convert decimal string to base b representation (most significant first)
vector<int> toBaseB(const string& dec, int b) {
    string s = dec;
    vector<int> digits;
    while (true) {
        int rem = 0;
        string next;
        bool hasNonZero = false;
        for (char c : s) {
            int cur = rem * 10 + (c - '0');
            int q = cur / b;
            rem = cur % b;
            if (q > 0 || hasNonZero) {
                next.push_back(static_cast<char>(q + '0'));
                hasNonZero = true;
            }
        }
        digits.push_back(rem);
        if (next.empty()) {
            break;
        }
        s = next;
    }
    reverse(digits.begin(), digits.end());
    if (digits.empty()) {
        digits.push_back(0);
    }
    return digits;
}

// Decimal string minus one
string decMinusOne(const string& s) {
    string result = s;
    int i = static_cast<int>(result.size()) - 1;
    while (i >= 0 && result[i] == '0') {
        result[i] = '9';
        i--;
    }
    if (i >= 0) {
        result[i]--;
    }
    // Remove leading zeros
    size_t start = 0;
    while (start + 1 < result.size() && result[start] == '0') {
        start++;
    }
    return result.substr(start);
}

// Count numbers in [0, X] with non-decreasing digits in base b
int countUpTo(const string& dec, int b) {
    vector<int> digits = toBaseB(dec, b);
    int n = static_cast<int>(digits.size());

    // memo[pos][prev][tight][started]
    vector<vector<vector<vector<int>>>> memo(
        n + 1,
        vector<vector<vector<int>>>(
            b + 1,
            vector<vector<int>>(2, vector<int>(2, -1))));

    function<int(int, int, bool, bool)> dfs =
        [&](int pos, int prev, bool tight, bool started) -> int {
        if (pos == n) {
            return 1;  // both 0 and regular numbers are valid
        }
        int& res = memo[pos][prev][tight ? 1 : 0][started ? 1 : 0];
        if (res != -1) return res;

        int limit = tight ? digits[pos] : (b - 1);
        int total = 0;

        for (int d = 0; d <= limit; d++) {
            if (!started) {
                if (d == 0) {
                    total = (total + dfs(pos + 1, 0, tight && (d == limit), false)) % MOD;
                } else {
                    total = (total + dfs(pos + 1, d, tight && (d == limit), true)) % MOD;
                }
            } else {
                if (d >= prev) {
                    total = (total + dfs(pos + 1, d, tight && (d == limit), true)) % MOD;
                }
            }
        }
        return res = total;
    };

    return dfs(0, 0, true, false);
}

int countNumbersImpl(const string& l, const string& r, int b) {
    int ansR = countUpTo(r, b);
    string lm1 = decMinusOne(l);
    int ansL = countUpTo(lm1, b);
    int result = (ansR - ansL) % MOD;
    if (result < 0) result += MOD;
    return result;
}

}  // namespace

CountNumbersWithNonDecreasingDigitsSolution::CountNumbersWithNonDecreasingDigitsSolution() {
    setMetaInfo({.id = 3519,
                 .title = "Count Numbers with Non-Decreasing Digits",
                 .url = "https://leetcode.com/problems/count-numbers-with-non-decreasing-digits/"});
    registerStrategy(
        {.name = "DigitDP",
         .expected = "Accepted",
         .time_complexity = "O(len(r) * log_b(10^len(r)) * b)",
         .space_complexity = "O(len(r) * log_b(10) * b)",
         .tags = {"Math", "String", "Dynamic Programming"}},
        countNumbersImpl);
}

int CountNumbersWithNonDecreasingDigitsSolution::countNumbers(string l, string r, int b) {
    return getSolution()(l, r, b);
}

}  // namespace problem_3519
}  // namespace leetcode
