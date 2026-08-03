#include "leetcode/problems/minimum-insertions-to-balance-a-parentheses-string.h"

#include <string>

namespace leetcode::problem_1541 {

namespace {

int minInsertionsImpl(const std::string& s) {
    int insertions = 0;
    int right = 0;  // number of ')' still owed to open '(' groups
    const int n = static_cast<int>(s.size());

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            right += 2;
        } else {  // s[i] == ')'
            if (i + 1 < n && s[i + 1] == ')') {
                // consume a contiguous "))" pair
                if (right > 0) {
                    right -= 2;
                } else {
                    ++insertions;  // insert '('
                }
                ++i;  // skip the second ')' of the pair
            } else {
                // isolated ')'
                if (right >= 2) {
                    right -= 2;
                    ++insertions;  // insert the missing partner ')'
                } else if (right == 1) {
                    right = 0;
                    ++insertions;  // insert the partner to complete "))"
                } else {  // right == 0
                    insertions += 2;  // insert '(' and ')'
                }
            }
        }
    }

    return insertions + right;
}

}  // namespace

MinimumInsertionsToBalanceAParenthesesStringSolution::MinimumInsertionsToBalanceAParenthesesStringSolution() {
    setMetaInfo({.id = 1541,
                 .title = "Minimum Insertions to Balance a Parentheses String",
                 .url = "https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/"});
    registerStrategy({.name = "greedy_count",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"String", "Stack", "Greedy"}},
                     minInsertionsImpl);
}

int MinimumInsertionsToBalanceAParenthesesStringSolution::minInsertions(std::string s) {
    return getSolution()(s);
}

}  // namespace leetcode::problem_1541
