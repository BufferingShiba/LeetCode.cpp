#include "leetcode/problems/minimum-genetic-mutation.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace leetcode {
namespace problem_433 {

// BFS: minimum number of mutations from start to end, where every intermediate
// gene must be present in the bank.
static int solution1(string startGene, string endGene, vector<string>& bank) {
  if (startGene == endGene) {
    return 0;
  }
  std::unordered_set<string> bankSet(bank.begin(), bank.end());
  if (bankSet.find(endGene) == bankSet.end()) {
    return -1;
  }

  std::unordered_map<string, int> dist;
  std::queue<string> q;
  dist[startGene] = 0;
  q.push(startGene);

  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    int d = dist[cur];
    if (cur == endGene) {
      return d;
    }
    // Try all 8 positions, each can be mutated to one of 4 chars.
    for (int i = 0; i < 8; ++i) {
      char original = cur[i];
      static const char genes[] = {'A', 'C', 'G', 'T'};
      for (char c : genes) {
        if (c == original) continue;
        cur[i] = c;
        if (bankSet.find(cur) != bankSet.end() &&
            dist.find(cur) == dist.end()) {
          dist[cur] = d + 1;
          q.push(cur);
        }
      }
      cur[i] = original;
    }
  }
  return -1;
}

MinimumGeneticMutationSolution::MinimumGeneticMutationSolution() {
  setMetaInfo({
      .id = 433,
      .title = "Minimum Genetic Mutation",
      .url = "https://leetcode.com/problems/minimum-genetic-mutation"
  });
  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(N*8*4) where N is bank size (<=10)",
       .space_complexity = "O(N*len)",
       .tags = {"BFS", "String"}},
      solution1);
}

int MinimumGeneticMutationSolution::minMutation(string startGene, string endGene,
                                               vector<string>& bank) {
  return getSolution()(startGene, endGene, bank);
}

}  // namespace problem_433
}  // namespace leetcode
