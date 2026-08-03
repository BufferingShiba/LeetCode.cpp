#include "leetcode/problems/shortest-string-that-contains-three-strings.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2800 {

namespace {

// Check if t is a substring of s
bool isSubstring(const std::string& s, const std::string& t) {
  return s.find(t) != std::string::npos;
}

// Merge s and t (s appears before t in the result).
// Maximizes suffix-prefix overlap to get the shortest result.
// If one string contains the other, returns the longer one.
std::string merge(const std::string& s, const std::string& t) {
  if (isSubstring(s, t)) return s;
  if (isSubstring(t, s)) return t;

  int n = static_cast<int>(s.size());
  int m = static_cast<int>(t.size());
  int max_overlap = 0;
  int limit = std::min(n, m);
  for (int k = limit; k >= 1; --k) {
    if (s.substr(n - k) == t.substr(0, k)) {
      max_overlap = k;
      break;
    }
  }
  return s + t.substr(max_overlap);
}

std::string minimumStringImpl(std::string a, std::string b, std::string c) {
  std::vector<std::string> cand = {a, b, c};

  // Remove strings that are substrings of another (keep the longer one;
  // for equal strings, keep the one with smaller original index).
  std::vector<std::string> filtered;
  for (int i = 0; i < 3; ++i) {
    bool contained = false;
    for (int j = 0; j < 3; ++j) {
      if (i == j) continue;
      if (isSubstring(cand[j], cand[i])) {
        // Remove if strictly shorter, or equal length but larger index
        if (cand[i].size() < cand[j].size() ||
            (cand[i].size() == cand[j].size() && i > j)) {
          contained = true;
          break;
        }
      }
    }
    if (!contained) {
      filtered.push_back(cand[i]);
    }
  }

  // Enumerate all permutations of the remaining strings
  std::vector<int> perm(filtered.size());
  for (int i = 0; i < static_cast<int>(perm.size()); ++i) {
    perm[i] = i;
  }

  std::string best;
  do {
    std::string cur = filtered[perm[0]];
    for (int i = 1; i < static_cast<int>(filtered.size()); ++i) {
      cur = merge(cur, filtered[perm[i]]);
    }
    if (best.empty() || cur.size() < best.size() ||
        (cur.size() == best.size() && cur < best)) {
      best = cur;
    }
  } while (std::next_permutation(perm.begin(), perm.end()));

  return best;
}

}  // anonymous namespace

ShortestStringThatContainsThreeStringsSolution::
    ShortestStringThatContainsThreeStringsSolution() {
  setMetaInfo({.id = 2800,
               .title = "Shortest String That Contains Three Strings",
               .url = "https://leetcode.com/problems/shortest-string-that-contains-three-strings/"});
  registerStrategy(
      {.name = "enumeration",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"String", "Greedy", "Enumeration"}},
      minimumStringImpl);
}

std::string ShortestStringThatContainsThreeStringsSolution::minimumString(
    std::string a, std::string b, std::string c) {
  return getSolution()(a, b, c);
}

}  // namespace problem_2800
}  // namespace leetcode
