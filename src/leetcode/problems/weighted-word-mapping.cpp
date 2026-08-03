#include "leetcode/problems/weighted-word-mapping.h"

namespace leetcode {
namespace problem_3838 {

namespace {

std::string mapWordWeightsImpl(std::vector<std::string>& words, std::vector<int>& weights) {
  std::string result;
  result.reserve(words.size());
  for (const std::string& word : words) {
    int sum = 0;
    for (char c : word) {
      sum += weights[c - 'a'];
    }
    int r = sum % 26;
    result.push_back(static_cast<char>('z' - r));
  }
  return result;
}

}  // namespace

WeightedWordMappingSolution::WeightedWordMappingSolution() {
  setMetaInfo({.id = 3838,
               .title = "Weighted Word Mapping",
               .url = "https://leetcode.com/problems/weighted-word-mapping/"});
  registerStrategy(
      {.name = "Simulation", .expected = "Accepted", .time_complexity = "O(L)", .space_complexity = "O(1)",
       .tags = {"Array", "String", "Simulation"}},
      mapWordWeightsImpl);
}

std::string WeightedWordMappingSolution::mapWordWeights(std::vector<std::string>& words,
                                                        std::vector<int>& weights) {
  return getSolution()(words, weights);
}

}  // namespace problem_3838
}  // namespace leetcode
