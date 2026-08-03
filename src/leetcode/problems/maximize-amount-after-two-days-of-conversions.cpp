#include "leetcode/problems/maximize-amount-after-two-days-of-conversions.h"

#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3387 {

namespace {

using Graph = std::unordered_map<std::string,
                                 std::vector<std::pair<std::string, double>>>;

Graph buildGraph(const std::vector<std::vector<std::string>>& pairs,
                 const std::vector<double>& rates) {
  Graph g;
  for (size_t i = 0; i < pairs.size(); ++i) {
    const std::string& a = pairs[i][0];
    const std::string& b = pairs[i][1];
    g[a].push_back({b, rates[i]});
    g[b].push_back({a, 1.0 / rates[i]});
  }
  return g;
}

std::unordered_map<std::string, double> bfsMultiplier(
    const Graph& g, const std::string& start) {
  std::unordered_map<std::string, double> mult;
  std::queue<std::string> q;
  mult[start] = 1.0;
  q.push(start);
  while (!q.empty()) {
    std::string cur = q.front();
    q.pop();
    auto it = g.find(cur);
    if (it == g.end()) continue;
    for (const auto& [next, r] : it->second) {
      if (mult.find(next) == mult.end()) {
        mult[next] = mult[cur] * r;
        q.push(next);
      }
    }
  }
  return mult;
}

// 计算 day2 图中从每个可达币种转回 start 的倍率：
// 先求 start -> c 的倍率 mult2[c]，则 c -> start 的倍率为 1 / mult2[c]。
double solve(std::string initialCurrency,
             std::vector<std::vector<std::string>>& pairs1,
             std::vector<double>& rates1,
             std::vector<std::vector<std::string>>& pairs2,
             std::vector<double>& rates2) {
  Graph g1 = buildGraph(pairs1, rates1);
  Graph g2 = buildGraph(pairs2, rates2);

  auto mult1 = bfsMultiplier(g1, initialCurrency);
  auto mult2 = bfsMultiplier(g2, initialCurrency);

  double best = 1.0;
  // 每个币种 C：day1 从 initial 到 C 得 mult1[C]，day2 从 C 转回 initial 用 1/mult2[C]。
  for (const auto& [c, m1] : mult1) {
    auto it = mult2.find(c);
    if (it != mult2.end()) {
      best = std::max(best, m1 / it->second);
    }
  }
  return best;
}

}  // namespace

MaximizeAmountAfterTwoDaysOfConversions::
    MaximizeAmountAfterTwoDaysOfConversions() {
  setMetaInfo({.id = 3387,
               .title = "Maximize Amount After Two Days of Conversions",
               .url = "https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/"});
  registerStrategy(
      {.name = "bfs_conversion_graphs",
       .expected = "Accepted",
       .time_complexity = "O(V + E)",
       .space_complexity = "O(V + E)",
       .tags = {"Depth-First Search", "Breadth-First Search", "Graph Theory"}},
      solve);
}

double MaximizeAmountAfterTwoDaysOfConversions::maxAmount(
    std::string initialCurrency,
    std::vector<std::vector<std::string>>& pairs1,
    std::vector<double>& rates1,
    std::vector<std::vector<std::string>>& pairs2,
    std::vector<double>& rates2) {
  return getSolution()(initialCurrency, pairs1, rates1, pairs2, rates2);
}

}  // namespace problem_3387
}  // namespace leetcode
