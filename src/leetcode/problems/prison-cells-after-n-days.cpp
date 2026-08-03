#include "leetcode/problems/prison-cells-after-n-days.h"

#include <unordered_map>

namespace leetcode {
namespace problem_957 {

static vector<int> solution1(vector<int>& cells, int n) {
  auto next = [](const vector<int>& cur) {
    vector<int> nxt(8, 0);
    for (int i = 1; i < 7; ++i) {
      nxt[i] = (cur[i - 1] == cur[i + 1]) ? 1 : 0;
    }
    return nxt;
  };

  // Detect cycle. Since there are only 8 cells, after the first day the state
  // is guaranteed to enter a cycle with period at most 2^6 = 64.
  unordered_map<string, int> seen;
  vector<vector<int>> states;
  states.push_back(cells);

  int day = 0;
  while (day < n) {
    cells = next(cells);
    ++day;

    // Build a key for the current state.
    string key(cells.begin(), cells.end());
    if (seen.count(key)) {
      // We found a cycle: states[seen[key]] .. states[day-1] repeats.
      int start = seen[key];
      int cycleLen = day - start;
      int remaining = n - day;  // steps left after reaching the repeated state
      int idx = start + (remaining % cycleLen);
      return states[idx];
    }
    seen[key] = day;
    states.push_back(cells);
  }

  return cells;
}

PrisonCellsAfterNDaysSolution::PrisonCellsAfterNDaysSolution() {
  setMetaInfo({
      .id = 957,
      .title = "Prison Cells After N Days",
      .url = "https://leetcode.com/problems/prison-cells-after-n-days"
  });
  registerStrategy(
      {.name = "Cycle Detection",
       .expected = "Accepted",
       .time_complexity = "O(64) = O(1)",
       .space_complexity = "O(64) = O(1)",
       .tags = {"Hash Table", "Simulation"}},
      solution1);
}

vector<int> PrisonCellsAfterNDaysSolution::prisonAfterNDays(vector<int>& cells, int n) {
  return getSolution()(cells, n);
}

}  // namespace problem_957
}  // namespace leetcode
