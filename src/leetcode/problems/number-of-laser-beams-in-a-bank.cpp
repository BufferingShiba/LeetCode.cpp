#include "leetcode/problems/number-of-laser-beams-in-a-bank.h"

namespace leetcode::problem_2125 {

namespace {

int numberOfBeamsImpl(std::vector<std::string>& bank) {
    int total = 0;
    int prev = 0;
    for (const auto& row : bank) {
        int cur = 0;
        for (char ch : row) {
            if (ch == '1') {
                ++cur;
            }
        }
        if (cur > 0) {
            total += prev * cur;
            prev = cur;
        }
    }
    return total;
}

}  // namespace

NumberOfLaserBeamsInABankSolution::NumberOfLaserBeamsInABankSolution() {
    setMetaInfo({.id = 2125,
                 .title = "Number of Laser Beams in a Bank",
                 .url = "https://leetcode.com/problems/number-of-laser-beams-in-a-bank/"});
    registerStrategy(
        {.name = "sequential-scan",
         .expected = "Accepted",
         .time_complexity = "O(m*n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Math", "String", "Matrix"}},
        numberOfBeamsImpl);
}

int NumberOfLaserBeamsInABankSolution::numberOfBeams(
    std::vector<std::string>& bank) {
    return getSolution()(bank);
}

}  // namespace leetcode::problem_2125
