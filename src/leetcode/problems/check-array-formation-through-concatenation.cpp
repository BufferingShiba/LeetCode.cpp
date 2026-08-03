#include "leetcode/problems/check-array-formation-through-concatenation.h"

#include <unordered_map>

namespace leetcode::problem_1640 {

namespace {

// Map first element of each piece to its index in pieces, then greedily scan arr.
bool canFormArrayImpl(std::vector<int>& arr,
                      std::vector<std::vector<int>>& pieces) {
  std::unordered_map<int, int> headToPiece;
  for (int i = 0; i < static_cast<int>(pieces.size()); ++i) {
    headToPiece[pieces[i][0]] = i;
  }

  int i = 0;
  while (i < static_cast<int>(arr.size())) {
    auto it = headToPiece.find(arr[i]);
    if (it == headToPiece.end()) {
      return false;
    }
    const auto& piece = pieces[it->second];
    for (int j = 0; j < static_cast<int>(piece.size()); ++j) {
      if (piece[j] != arr[i + j]) {
        return false;
      }
    }
    i += static_cast<int>(piece.size());
  }
  return true;
}

}  // namespace

CheckArrayFormationThroughConcatenationSolution::
    CheckArrayFormationThroughConcatenationSolution() {
  setMetaInfo({.id = 1640,
               .title = "Check Array Formation Through Concatenation",
               .url = "https://leetcode.com/problems/check-array-formation-through-concatenation/"});

  registerStrategy({.name = "hashmap-first-element",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(m)",
                    .tags = {"Array", "Hash Table"}},
                   canFormArrayImpl);
}

bool CheckArrayFormationThroughConcatenationSolution::canFormArray(
    std::vector<int>& arr, std::vector<std::vector<int>>& pieces) {
  return getSolution()(arr, pieces);
}

}  // namespace leetcode::problem_1640
