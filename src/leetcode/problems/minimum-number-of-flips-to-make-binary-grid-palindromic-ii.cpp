#include "leetcode/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii.h"

#include <algorithm>
#include <climits>

namespace leetcode::problem_3240 {

namespace {

int minFlipsImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  int c4 = 0;       // total cost of all 4-cell symmetric groups
  int diffQ = 0;    // 2-cell groups whose two values differ
  int same0Q = 0;   // 2-cell groups both zero
  int same1Q = 0;   // 2-cell groups both one
  int center = -1;  // value of the unique center cell, -1 if absent

  for (int i = 0; i < (m + 1) / 2; ++i) {
    for (int j = 0; j < (n + 1) / 2; ++j) {
      const int ai = m - 1 - i;
      const int bj = n - 1 - j;

      int ones = 0;
      int sz = 0;
      auto add = [&](int v) {
        ++sz;
        ones += v;
      };

      add(grid[i][j]);
      if (bj != j) add(grid[i][bj]);
      if (ai != i) add(grid[ai][j]);
      if (ai != i && bj != j) add(grid[ai][bj]);

      if (sz == 4) {
        c4 += std::min(ones, 4 - ones);
      } else if (sz == 2) {
        if (ones == 0) {
          ++same0Q;
        } else if (ones == 2) {
          ++same1Q;
        } else {
          ++diffQ;
        }
      } else {  // sz == 1, the unique center cell
        center = ones;
      }
    }
  }

  // Base configuration: every group chooses its lowest-cost option.
  // 4-groups contribute 0 or 4 ones -> always 0 mod 4.
  // 2-groups (diff, same0) contribute 0; same1 contributes 2.
  // Center contributes its value v.
  const int base_mod =
      ((same1Q * 2) % 4 + (center == 1 ? 1 : (center == 0 ? 0 : 0))) % 4;
  const long long base_cost =
      static_cast<long long>(c4) + static_cast<long long>(diffQ);
  const int target_need = (4 - base_mod) % 4;

  // Compute minimum additional cost to gain a needed "+/-2 (mod 4)"
  // adjustment using flexible symmetric groups.
  auto extra2 = [&](int need) -> int {
    need %= 4;
    if (need < 0) need += 4;
    if (need == 0) return 0;
    if (need == 2) {
      if (diffQ >= 1) return 0;               // flip a diff group's choice, cost 0
      if (same0Q + same1Q >= 1) return 2;     // swap a same group, cost 2
    }
    return -1;  // infeasible with only +/-2 resources
  };

  long long best = LLONG_MAX;

  if (center == -1) {
    // No center: only +/-2 adjustments available.
    const int x = extra2(target_need);
    if (x != -1) best = std::min(best, base_cost + x);
  } else {
    // Option A: keep the center cell as-is.
    {
      const int x = extra2(target_need);
      if (x != -1) best = std::min(best, base_cost + x);
    }
    // Option B: flip the center cell (cost 1), contribution changes by +/-1.
    {
      int delta = (center == 0) ? 1 : -1;
      delta %= 4;
      if (delta < 0) delta += 4;
      const int new_mod = (base_mod + delta) % 4;
      const int need = (4 - new_mod) % 4;
      const int y = extra2(need);
      if (y != -1) best = std::min(best, base_cost + 1 + y);
    }
  }

  return static_cast<int>(best);
}

}  // namespace

MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution::
    MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution() {
  setMetaInfo(
      {.id = 3240,
       .title = "Minimum Number of Flips to Make Binary Grid Palindromic II",
       .url = "https://leetcode.com/problems/minimum-number-of-flips-to-make-"
              "binary-grid-palindromic-ii/"});

  registerStrategy(
      {.name = "symmetric-groups",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Matrix", "Greedy"},
       .notes = "Group cells by origin symmetry. 4-groups cost min(ones,"
                "4-ones) and always contribute 0 mod 4; adjust the "
                "remainder using 2-groups (+/-2) and the center (+/-1)."},
      minFlipsImpl);
}

int MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution::minFlips(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_3240
