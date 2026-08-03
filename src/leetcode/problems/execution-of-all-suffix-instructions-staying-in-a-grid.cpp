#include "leetcode/problems/execution-of-all-suffix-instructions-staying-in-a-grid.h"

namespace leetcode::problem_2120 {

static std::vector<int> executeInstructionsImpl(int n, std::vector<int>& startPos,
                                                 std::string s) {
    int m = static_cast<int>(s.size());
    std::vector<int> answer(m);

    for (int i = 0; i < m; ++i) {
        int row = startPos[0];
        int col = startPos[1];
        int count = 0;

        for (int j = i; j < m; ++j) {
            char c = s[j];
            if (c == 'L')
                --col;
            else if (c == 'R')
                ++col;
            else if (c == 'U')
                --row;
            else  // 'D'
                ++row;

            if (row < 0 || row >= n || col < 0 || col >= n) {
                break;
            }
            ++count;
        }

        answer[i] = count;
    }

    return answer;
}

ExecutionOfAllSuffixInstructionsStayingInAGridSolution::
    ExecutionOfAllSuffixInstructionsStayingInAGridSolution() {
    setMetaInfo({2120,
                 "Execution of All Suffix Instructions Staying in a Grid",
                 "https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/"});
    registerStrategy(
        {"Simulation",
         "Accepted",
         "O(m^2)",
         "O(1)",
         std::vector<std::string>{"String", "Simulation"},
         ""},
        executeInstructionsImpl);
}

std::vector<int>
ExecutionOfAllSuffixInstructionsStayingInAGridSolution::executeInstructions(
    int n, std::vector<int>& startPos, std::string s) {
    return getSolution()(n, startPos, s);
}

}  // namespace leetcode::problem_2120
