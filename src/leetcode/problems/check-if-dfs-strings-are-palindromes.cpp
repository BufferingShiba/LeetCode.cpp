#include "leetcode/problems/check-if-dfs-strings-are-palindromes.h"

#include <functional>

namespace leetcode {
namespace problem_3327 {

namespace {
constexpr long long kMod1 = 1000000007LL;
constexpr long long kMod2 = 1000000009LL;
constexpr long long kBase = 131LL;

struct NodeInfo {
  long long fh1, fh2;  // Forward (low-to-high position) hashes.
  long long rh1, rh2;  // Reverse (high-to-low position) hashes.
  int len;             // Length of the DFS string of this subtree.
};

std::vector<bool> findAnswerImpl(std::vector<int>& parent, std::string s) {
  const int n = static_cast<int>(parent.size());
  std::vector<std::vector<int>> children(n);
  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (parent[i] == -1) {
      root = i;
    } else {
      // Iterating i in increasing order keeps each child list sorted.
      children[parent[i]].push_back(i);
    }
  }

  std::vector<long long> pw1(n + 2), pw2(n + 2);
  pw1[0] = 1;
  pw2[0] = 1;
  for (int i = 1; i < static_cast<int>(pw1.size()); ++i) {
    pw1[i] = (pw1[i - 1] * kBase) % kMod1;
    pw2[i] = (pw2[i - 1] * kBase) % kMod2;
  }

  std::vector<NodeInfo> info(n);
  std::vector<bool> answer(n, false);

  std::function<void(int)> dfs = [&](int u) {
    long long fh1 = 0, fh2 = 0;
    long long rh1 = 0, rh2 = 0;
    int len = 0;
    for (int c : children[u]) {
      dfs(c);
      const NodeInfo& ci = info[c];
      // Forward concat: f(A + B) = f(A) + f(B) * base^|A|.
      fh1 = (fh1 + ci.fh1 * pw1[len]) % kMod1;
      fh2 = (fh2 + ci.fh2 * pw2[len]) % kMod2;
      // Reverse concat: r(A + B) = r(A) * base^|B| + r(B).
      rh1 = (rh1 * pw1[ci.len] + ci.rh1) % kMod1;
      rh2 = (rh2 * pw2[ci.len] + ci.rh2) % kMod2;
      len += ci.len;
    }
    const long long val = static_cast<long long>(s[u] - 'a' + 1);
    fh1 = (fh1 + val * pw1[len]) % kMod1;
    fh2 = (fh2 + val * pw2[len]) % kMod2;
    rh1 = (rh1 * kBase + val) % kMod1;
    rh2 = (rh2 * kBase + val) % kMod2;
    info[u] = {fh1, fh2, rh1, rh2, len + 1};
    answer[u] = (fh1 == rh1) && (fh2 == rh2);
  };

  dfs(root);
  return answer;
}
}  // namespace

CheckIfDfsStringsArePalindromesSolution::
    CheckIfDfsStringsArePalindromesSolution() {
  setMetaInfo({.id = 3327,
               .title = "Check if DFS Strings Are Palindromes",
               .url = "https://leetcode.com/problems/check-if-dfs-strings-are-palindromes/"});
  registerStrategy(
      {.name = "DoubleHashPostorder",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Hash Function", "Depth-First Search", "String"}},
      [](std::vector<int>& parent, std::string s) -> std::vector<bool> {
        return findAnswerImpl(parent, s);
      });
}

std::vector<bool>
CheckIfDfsStringsArePalindromesSolution::findAnswer(std::vector<int>& parent,
                                                     std::string s) {
  return getSolution()(parent, s);
}

}  // namespace problem_3327
}  // namespace leetcode
