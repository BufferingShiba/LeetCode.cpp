#include "leetcode/problems/compare-version-numbers.h"

namespace leetcode::problem_165 {

namespace {

int compareVersionTwoPointers(const std::string& version1, const std::string& version2) {
    int i = 0, j = 0;
    const int n = static_cast<int>(version1.size());
    const int m = static_cast<int>(version2.size());

    while (i < n || j < m) {
        int v1 = 0, v2 = 0;

        while (i < n && version1[i] != '.') {
            v1 = v1 * 10 + (version1[i] - '0');
            ++i;
        }
        ++i;  // skip '.' or run past end

        while (j < m && version2[j] != '.') {
            v2 = v2 * 10 + (version2[j] - '0');
            ++j;
        }
        ++j;

        if (v1 < v2) return -1;
        if (v1 > v2) return 1;
    }

    return 0;
}

}  // namespace

CompareVersionNumbersSolution::CompareVersionNumbersSolution() {
    setMetaInfo({.id = 165,
                 .title = "Compare Version Numbers",
                 .url = "https://leetcode.com/problems/compare-version-numbers/"});

    registerStrategy({.name = "TwoPointers",
                      .expected = "Accepted",
                      .time_complexity = "O(n + m)",
                      .space_complexity = "O(1)",
                      .tags = {"TwoPointers", "String"}},
                     compareVersionTwoPointers);
}

}  // namespace leetcode::problem_165
