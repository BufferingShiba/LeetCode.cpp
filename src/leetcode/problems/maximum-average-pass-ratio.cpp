#include "leetcode/problems/maximum-average-pass-ratio.h"

#include <queue>
#include <tuple>
#include <vector>

namespace {

double maxAverageRatioImpl(std::vector<std::vector<int>>& classes, int extraStudents) {
    // 边际增益：给班级增加一个学生后通过率的提升
    // gain = (pass+1)/(total+1) - pass/total = (total-pass) / (total*(total+1))
    auto gain = [](int pass, int total) -> double {
        return static_cast<double>(total - pass) /
               (static_cast<double>(total) * (total + 1));
    };

    // 最大堆，按增益从大到小排列
    std::priority_queue<std::tuple<double, int, int>> pq;
    double sum = 0.0;

    for (const auto& c : classes) {
        int pass = c[0], total = c[1];
        pq.emplace(gain(pass, total), pass, total);
        sum += static_cast<double>(pass) / total;
    }

    while (extraStudents-- > 0) {
        auto [g, pass, total] = pq.top();
        pq.pop();
        sum += g;  // 通过率增量正好等于边际增益
        ++pass;
        ++total;
        pq.emplace(gain(pass, total), pass, total);
    }

    return sum / classes.size();
}

}  // namespace

namespace leetcode::problem_1792 {

MaximumAveragePassRatioSolution::MaximumAveragePassRatioSolution() {
    setMetaInfo({.id = 1792,
                 .title = "Maximum Average Pass Ratio",
                 .url = "https://leetcode.com/problems/maximum-average-pass-ratio/"});
    registerStrategy({.name = "GreedyMaxHeap",
                      .expected = "Accepted",
                      .time_complexity = "O((N + E) log N)",
                      .space_complexity = "O(N)",
                      .tags = {"Array", "Greedy", "Heap (Priority Queue)"}},
                     maxAverageRatioImpl);
}

double MaximumAveragePassRatioSolution::maxAverageRatio(
    std::vector<std::vector<int>>& classes, int extraStudents) {
    return getSolution()(classes, extraStudents);
}

}  // namespace leetcode::problem_1792
