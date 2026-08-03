#include "leetcode/problems/minimize-string-length.h"

namespace leetcode {
namespace problem_2716 {

namespace {

int minimizedStringLengthImpl(std::string s) {
    bool seen[26] = {false};
    int count = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (!seen[idx]) {
            seen[idx] = true;
            ++count;
        }
    }
    return count;
}

}  // namespace

MinimizeStringLengthSolution::MinimizeStringLengthSolution() {
    setMetaInfo({2716, "Minimize String Length",
                  "https://leetcode.com/problems/minimize-string-length/"});
    registerStrategy({.name = "distinct-chars",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Hash Table", "String"}},
                     minimizedStringLengthImpl);
}

int MinimizeStringLengthSolution::minimizedStringLength(std::string s) {
    return getSolution()(s);
}

}  // namespace problem_2716
}  // namespace leetcode
