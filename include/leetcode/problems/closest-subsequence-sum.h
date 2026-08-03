#ifndef LEETCODE_PROBLEMS_CLOSEST_SUBSEQUENCE_SUM_H__
#define LEETCODE_PROBLEMS_CLOSEST_SUBSEQUENCE_SUM_H__

#include "leetcode/core.h"

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1755 {

using Func = std::function<int(std::vector<int>&, int)>;

class ClosestSubsequenceSumSolution : public SolutionBase<Func> {
public:
    ClosestSubsequenceSumSolution() {
        setMetaInfo({.id = 1755,
                     .title = "Closest Subsequence Sum",
                     .url = "https://leetcode.com/problems/closest-subsequence-sum/"});

        registerStrategy(
            {.name = "MeetInTheMiddleAndBinarySearch",
             .expected = "Accepted",
             .time_complexity = "O(2^(n/2) * log(2^(n/2)))",
             .space_complexity = "O(2^(n/2))",
             .tags = {"Meet in the Middle", "Sorting", "Binary Search", "Bit Manipulation"},
             .notes = "Split nums into two halves, enumerate all subsequence sums of each half, "
                      "then for each left sum binary-search the best right sum."},
            solveClosestSubsequenceSum);
    }

    int minAbsDifference(std::vector<int>& nums, int goal) {
        return getSolution()(nums, goal);
    }

private:
    static int solveClosestSubsequenceSum(std::vector<int>& nums, int goal);
};

}  // namespace problem_1755
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CLOSEST_SUBSEQUENCE_SUM_H__
