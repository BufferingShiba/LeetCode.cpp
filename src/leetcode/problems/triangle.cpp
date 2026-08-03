#include "leetcode/problems/triangle.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_120 {

static int minimumTotalImpl(std::vector<std::vector<int>>& triangle) {
    int n = static_cast<int>(triangle.size());
    std::vector<int> dp(triangle[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

TriangleSolution::TriangleSolution() {
    setMetaInfo({.id = 120, .title = "Triangle", .url = "https://leetcode.com/problems/triangle/"});
    registerStrategy(
        {.name = "bottomUpDP",
         .expected = "Accepted",
         .time_complexity = "O(N^2)",
         .space_complexity = "O(N)",
         .tags = {"Array", "Dynamic Programming"}},
        minimumTotalImpl);
    setDefaultStrategy();
}

int TriangleSolution::minimumTotal(std::vector<std::vector<int>>& triangle) {
    return getSolution()(triangle);
}

} // namespace leetcode::problem_120
