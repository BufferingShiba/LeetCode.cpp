#include "leetcode/problems/alphabet-board-path.h"

#include <string>

namespace leetcode::problem_1138 {

namespace {

// 从 (r1,c1) 到 (r2,c2) 的最小路径。注意 'z' 在第 6 行只有 1 列，需避免越界。
std::string alphabetBoardPathImpl(std::string target) {
    std::string result;
    int r = 0, c = 0;
    for (char ch : target) {
        int nr = (ch - 'a') / 5;
        int nc = (ch - 'a') % 5;

        if (nr == 5) {
            // 目标是 'z'：必须先水平（左移）再竖直（下移）。
            while (c > nc) { result.push_back('L'); --c; }
            while (r < nr) { result.push_back('D'); ++r; }
        } else {
            // 先竖直再水平，避免从 'z' 出发右移越界。
            while (r > nr) { result.push_back('U'); --r; }
            while (r < nr) { result.push_back('D'); ++r; }
            while (c > nc) { result.push_back('L'); --c; }
            while (c < nc) { result.push_back('R'); ++c; }
        }
        result.push_back('!');
        r = nr;
        c = nc;
    }
    return result;
}

}  // namespace

AlphabetBoardPathSolution::AlphabetBoardPathSolution() {
    setMetaInfo({.id = 1138,
                 .title = "Alphabet Board Path",
                 .url = "https://leetcode.com/problems/alphabet-board-path/"});
    registerStrategy({.name = "greedy",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Hash Table", "String"}},
                     &alphabetBoardPathImpl);
}

std::string AlphabetBoardPathSolution::alphabetBoardPath(std::string target) {
    return getSolution()(std::move(target));
}

}  // namespace leetcode::problem_1138
