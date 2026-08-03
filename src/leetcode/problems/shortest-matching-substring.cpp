#include "leetcode/problems/shortest-matching-substring.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3455 {

namespace {

const int INF = 1000000000;

// KMP: all start indices where pat occurs as a substring of s.
std::vector<int> occurrences(const std::string& s, const std::string& pat) {
  std::vector<int> occ;
  const int n = static_cast<int>(s.size());
  const int m = static_cast<int>(pat.size());
  if (m == 0) return occ;
  std::vector<int> pi(m, 0);
  for (int i = 1; i < m; ++i) {
    int j = pi[i - 1];
    while (j > 0 && pat[i] != pat[j]) j = pi[j - 1];
    if (pat[i] == pat[j]) ++j;
    pi[i] = j;
  }
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j > 0 && s[i] != pat[j]) j = pi[j - 1];
    if (s[i] == pat[j]) ++j;
    if (j == m) {
      occ.push_back(i - m + 1);
      j = pi[j - 1];
    }
  }
  return occ;
}

int shortestMatchingSubstringImpl(const std::string& s, const std::string& p) {
  std::vector<std::string> parts;
  std::size_t start = 0;
  for (std::size_t i = 0; i < p.size(); ++i) {
    if (p[i] == '*') {
      parts.push_back(p.substr(start, i - start));
      start = i + 1;
    }
  }
  parts.push_back(p.substr(start));

  const std::string& A = parts[0];
  const std::string& B = parts[1];
  const std::string& C = parts[2];

  const bool aEmpty = A.empty();
  const bool bEmpty = B.empty();
  const bool cEmpty = C.empty();

  if (aEmpty && bEmpty && cEmpty) return 0;

  const auto occA = occurrences(s, A);
  const auto occB = occurrences(s, B);
  const auto occC = occurrences(s, C);

  long long best = INF;

  if (!bEmpty) {
    for (int posB : occB) {
      int maxLeft;
      if (aEmpty) {
        maxLeft = posB;
      } else {
        const int limit = posB - static_cast<int>(A.size());
        auto it = std::upper_bound(occA.begin(), occA.end(), limit);
        if (it == occA.begin()) continue;
        maxLeft = *(it - 1);
      }
      int minRight;
      if (cEmpty) {
        minRight = posB + static_cast<int>(B.size());
      } else {
        const int need = posB + static_cast<int>(B.size());
        auto it = std::lower_bound(occC.begin(), occC.end(), need);
        if (it == occC.end()) continue;
        minRight = *it;
      }
      const long long len =
          static_cast<long long>(minRight) + C.size() - maxLeft;
      best = std::min(best, len);
    }
  } else {
    if (aEmpty) {
      if (!occC.empty()) best = std::min(best, static_cast<long long>(C.size()));
    } else if (cEmpty) {
      if (!occA.empty()) best = std::min(best, static_cast<long long>(A.size()));
    } else {
      for (int posC : occC) {
        const int limit = posC - static_cast<int>(A.size());
        auto it = std::upper_bound(occA.begin(), occA.end(), limit);
        if (it == occA.begin()) continue;
        const int maxLeft = *(it - 1);
        const long long len =
            static_cast<long long>(posC) + C.size() - maxLeft;
        best = std::min(best, len);
      }
    }
  }

  return (best >= INF) ? -1 : static_cast<int>(best);
}

}  // namespace

ShortestMatchingSubstringSolution::ShortestMatchingSubstringSolution() {
  setMetaInfo({3455, "Shortest Matching Substring",
               "https://leetcode.com/problems/shortest-matching-substring/"});
  registerStrategy(
      {.name = "splitKMPBinarySearch",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Two Pointers", "String", "Binary Search",
                "String Matching"}},
      shortestMatchingSubstringImpl);
}

int ShortestMatchingSubstringSolution::shortestMatchingSubstring(
    std::string s, std::string p) {
  return getSolution()(std::move(s), std::move(p));
}

}  // namespace problem_3455
}  // namespace leetcode
