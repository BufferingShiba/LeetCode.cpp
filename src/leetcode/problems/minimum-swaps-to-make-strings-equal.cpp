#include "leetcode/problems/minimum-swaps-to-make-strings-equal.h"

namespace leetcode::problem_1247 {

static int minimumSwapImpl(std::string s1, std::string s2) {
    int xy = 0, yx = 0;
    int n = static_cast<int>(s1.size());
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'x' && s2[i] == 'y') {
            ++xy;
        } else if (s1[i] == 'y' && s2[i] == 'x') {
            ++yx;
        }
    }
    if ((xy + yx) % 2 != 0) {
        return -1;
    }
    return xy / 2 + yx / 2 + (xy % 2) * 2;
}

int MinimumSwapsToMakeStringsEqualSolution::minimumSwap(std::string s1, std::string s2) {
    return getSolution()(s1, s2);
}

MinimumSwapsToMakeStringsEqualSolution::MinimumSwapsToMakeStringsEqualSolution() {
    setMetaInfo(1247, "Minimum Swaps to Make Strings Equal",
                "https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/");
    registerStrategy(
        {.name = "GreedyCounting",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Math", "String", "Greedy"}},
        minimumSwapImpl);
}

}  // namespace leetcode::problem_1247
