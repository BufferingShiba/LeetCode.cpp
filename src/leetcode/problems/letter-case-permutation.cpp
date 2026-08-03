#include "leetcode/problems/letter-case-permutation.h"

#include <cctype>

namespace leetcode::problem_784 {

namespace {

void dfs(std::string& s, int index, std::vector<std::string>& result) {
  if (index == static_cast<int>(s.size())) {
    result.push_back(s);
    return;
  }
  char c = s[index];
  if (std::isalpha(static_cast<unsigned char>(c))) {
    // Branch 1: keep as-is.
    dfs(s, index + 1, result);
    // Branch 2: flip case.
    if (std::islower(static_cast<unsigned char>(c))) {
      s[index] = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    } else {
      s[index] = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    dfs(s, index + 1, result);
  } else {
    dfs(s, index + 1, result);
  }
}

std::vector<std::string> letterCasePermutationImpl(std::string s) {
  std::vector<std::string> result;
  dfs(s, 0, result);
  return result;
}

}  // namespace

LetterCasePermutationSolution::LetterCasePermutationSolution() {
  setMetaInfo({.id = 784,
               .title = "Letter Case Permutation",
               .url = "https://leetcode.com/problems/letter-case-permutation/"});
  registerStrategy(
      {.name = "DFS (Backtracking)",
       .expected = "Accepted",
       .time_complexity = "O(2^k) where k is the number of letters",
       .space_complexity = "O(2^k) for the result plus O(k) recursion depth",
       .tags = {"String", "Backtracking"}},
      letterCasePermutationImpl);
}

std::vector<std::string> LetterCasePermutationSolution::letterCasePermutation(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_784
