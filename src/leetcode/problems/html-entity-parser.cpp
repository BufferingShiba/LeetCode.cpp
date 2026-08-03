#include "leetcode/problems/html-entity-parser.h"

#include <string>
#include <unordered_map>

namespace leetcode::problem_1410 {

namespace {

std::string entityParserImpl(const std::string& text) {
  static const std::unordered_map<std::string, char> kEntities = {
      {"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'},
      {"&gt;", '>'},    {"&lt;", '<'},    {"&frasl;", '/'}};

  std::string result;
  result.reserve(text.size());
  const std::size_t n = text.size();
  std::size_t i = 0;
  while (i < n) {
    if (text[i] != '&') {
      result.push_back(text[i]);
      ++i;
      continue;
    }
    bool matched = false;
    for (const auto& entry : kEntities) {
      const std::string& entity = entry.first;
      if (i + entity.size() <= n &&
          text.compare(i, entity.size(), entity) == 0) {
        result.push_back(entry.second);
        i += entity.size();
        matched = true;
        break;
      }
    }
    if (!matched) {
      result.push_back(text[i]);
      ++i;
    }
  }
  return result;
}

}  // namespace

std::string HtmlEntityParserSolution::entityParser(const std::string& text) {
  return getSolution()(text);
}

HtmlEntityParserSolution::HtmlEntityParserSolution() {
  setMetaInfo({.id = 1410,
               .title = "HTML Entity Parser",
               .url =
                   "https://leetcode.com/problems/html-entity-parser/"});
  registerStrategy(
      {.name = "hashmap-single-pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String"}},
      entityParserImpl);
}

}  // namespace leetcode::problem_1410
