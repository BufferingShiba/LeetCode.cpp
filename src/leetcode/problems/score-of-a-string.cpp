#include "leetcode/problems/score-of-a-string.h"

#include <cstdlib>

namespace leetcode::problem_3110 {

static int scoreOfStringImpl(std::string s) {
    int score = 0;
    for (size_t i = 1; i < s.size(); ++i) {
        score += std::abs(s[i] - s[i - 1]);
    }
    return score;
}

ScoreOfAStringSolution::ScoreOfAStringSolution() {
    setMetaInfo({.id = 3110,
                 .title = "Score of a String",
                 .url = "https://leetcode.com/problems/score-of-a-string/"});
    registerStrategy({.name = "LinearScan",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"String"}},
                     scoreOfStringImpl);
    setDefaultStrategy();
}

int ScoreOfAStringSolution::scoreOfString(std::string s) {
    return getSolution()(s);
}

}  // namespace leetcode::problem_3110
