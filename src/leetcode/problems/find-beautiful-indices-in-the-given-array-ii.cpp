#include "leetcode/problems/find-beautiful-indices-in-the-given-array-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3008 {
namespace {

// KMP prefix function.
std::vector<int> buildPrefix(const std::string& pat) {
  int m = static_cast<int>(pat.size());
  std::vector<int> pi(m, 0);
  for (int i = 1; i < m; ++i) {
    int j = pi[i - 1];
    while (j > 0 && pat[i] != pat[j]) j = pi[j - 1];
    if (pat[i] == pat[j]) ++j;
    pi[i] = j;
  }
  return pi;
}

// Find all occurrence start indices of pattern in text.
std::vector<int> findAllOccurrences(const std::string& text,
                                    const std::string& pat) {
  if (pat.empty()) return {};
  int n = static_cast<int>(text.size());
  int m = static_cast<int>(pat.size());
  std::vector<int> pi = buildPrefix(pat);
  std::vector<int> result;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j > 0 && text[i] != pat[j]) j = pi[j - 1];
    if (text[i] == pat[j]) ++j;
    if (j == m) {
      result.push_back(i - m + 1);
      j = pi[j - 1];
    }
  }
  return result;
}

std::vector<int> beautifulIndicesImpl(std::string s, std::string a,
                                      std::string b, int k) {
  std::vector<int> positionsA = findAllOccurrences(s, a);
  std::vector<int> positionsB = findAllOccurrences(s, b);

  std::vector<int> result;
  result.reserve(positionsA.size());

  for (int i : positionsA) {
    int lo = i - k;
    int hi = i + k;
    // Check if there exists j in positionsB with lo <= j <= hi.
    auto it = std::lower_bound(positionsB.begin(), positionsB.end(), lo);
    if (it != positionsB.end() && *it <= hi) {
      result.push_back(i);
    }
  }

  return result;
}

}  // namespace

FindBeautifulIndicesInTheGivenArrayIiSolution::
    FindBeautifulIndicesInTheGivenArrayIiSolution() {
  setMetaInfo({3008, "Find Beautiful Indices in the Given Array II",
               "https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/"});

  registerStrategy(
      {"KMP + Binary Search", "Accepted", "O(|s| + |a| + |b| + |A|log|B|)",
       "O(|s|)", {"Two Pointers", "String", "Binary Search", "String Matching"}},
      beautifulIndicesImpl);
}

std::vector<int> FindBeautifulIndicesInTheGivenArrayIiSolution::beautifulIndices(
    std::string s, std::string a, std::string b, int k) {
  return getSolution()(s, a, b, k);
}

}  // namespace problem_3008
}  // namespace leetcode
