#include "leetcode/problems/relative-ranks.h"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

namespace leetcode::problem_506 {

namespace {

std::vector<std::string> findRelativeRanksImpl(std::vector<int>& score) {
    const int n = static_cast<int>(score.size());
    std::vector<std::pair<int, int>> indexed;  // (score, original_index)
    indexed.reserve(n);
    for (int i = 0; i < n; ++i) {
        indexed.emplace_back(score[i], i);
    }
    std::sort(indexed.begin(), indexed.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  return a.first > b.first;
              });

    std::vector<std::string> result(n);
    for (int rank = 1; rank <= n; ++rank) {
        const int idx = indexed[rank - 1].second;
        if (rank == 1) {
            result[idx] = "Gold Medal";
        } else if (rank == 2) {
            result[idx] = "Silver Medal";
        } else if (rank == 3) {
            result[idx] = "Bronze Medal";
        } else {
            result[idx] = std::to_string(rank);
        }
    }
    return result;
}

}  // namespace

RelativeRanksSolution::RelativeRanksSolution() {
    setMetaInfo({.id = 506,
                 .title = "Relative Ranks",
                 .url = "https://leetcode.com/problems/relative-ranks/"});
    registerStrategy({.name = "Sorting Desc",
                      .expected = "Accepted",
                      .time_complexity = "O(n log n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Sorting", "Heap (Priority Queue)"}},
                     &findRelativeRanksImpl);
}

std::vector<std::string> RelativeRanksSolution::findRelativeRanks(std::vector<int>& score) {
    return getSolution()(score);
}

}  // namespace leetcode::problem_506
