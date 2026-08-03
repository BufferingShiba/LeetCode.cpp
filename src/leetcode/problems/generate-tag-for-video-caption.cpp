#include "leetcode/problems/generate-tag-for-video-caption.h"

#include <cctype>
#include <sstream>

namespace leetcode {
namespace problem_3582 {

namespace {

std::string generateTagImpl(std::string caption) {
  std::string result = "#";
  std::istringstream iss(caption);
  std::string word;
  bool first = true;

  while (iss >> word) {
    if (!first && !word.empty()) {
      word[0] = static_cast<char>(std::toupper(word[0]));
    }
    for (size_t i = (first ? 0 : 1); i < word.size(); ++i) {
      word[i] = static_cast<char>(std::tolower(word[i]));
    }
    result += word;
    first = false;
  }

  std::string cleaned;
  cleaned += '#';
  for (size_t i = 1; i < result.size(); ++i) {
    if (std::isalpha(result[i])) cleaned += result[i];
  }

  if (cleaned.size() > 100) cleaned = cleaned.substr(0, 100);
  return cleaned;
}

}  // namespace

GenerateTagForVideoCaptionSolution::GenerateTagForVideoCaptionSolution() {
  setMetaInfo({.id = 3582,
               .title = "Generate Tag for Video Caption",
               .url =
                   "https://leetcode.com/problems/generate-tag-for-video-caption/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Simulation"}},
      generateTagImpl);
}

std::string GenerateTagForVideoCaptionSolution::generateTag(std::string caption) {
  return getSolution()(std::move(caption));
}

}  // namespace problem_3582
}  // namespace leetcode
