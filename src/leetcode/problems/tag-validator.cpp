#include "leetcode/problems/tag-validator.h"

#include <cctype>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_591 {

namespace {

bool IsValidTagName(const std::string& name) {
  if (name.empty() || name.size() > 9) {
    return false;
  }
  for (char c : name) {
    if (c < 'A' || c > 'Z') {
      return false;
    }
  }
  return true;
}

}  // namespace

bool isValidImpl(const std::string& code) {
  const int n = static_cast<int>(code.size());
  std::vector<std::string> stack;
  int i = 0;

  // The whole code must be wrapped in a single closed tag, so it must start
  // with '<' and that must be a start tag (not '</' or '<!').
  if (n == 0 || code[0] != '<') {
    return false;
  }

  // Whether the single top-level closed tag has already been closed.
  bool topLevelClosed = false;

  while (i < n) {
    if (code[i] != '<') {
      // Plain text outside a tag. Only allowed inside a tag (stack non-empty).
      if (stack.empty()) {
        return false;
      }
      ++i;
      continue;
    }

    // code[i] == '<'
    if (i + 1 < n && code[i + 1] == '/') {
      // End tag: </NAME>
      int j = i + 2;
      std::string name;
      while (j < n && code[j] != '>') {
        name.push_back(code[j]);
        ++j;
      }
      if (j >= n) {
        // no closing '>' found -> unmatched '<'
        return false;
      }
      ++j;  // skip '>'
      if (stack.empty()) {
        return false;
      }
      if (!IsValidTagName(name) || stack.back() != name) {
        return false;
      }
      stack.pop_back();
      if (stack.empty()) {
        topLevelClosed = true;
      }
      i = j;
      continue;
    }

    if (i + 1 < n && code[i + 1] == '!') {
      // CDATA: <![CDATA[ ... ]]>
      if (!(i + 9 <= n && code.compare(i, 9, "<![CDATA[") == 0)) {
        return false;
      }
      // CDATA only allowed inside a tag (stack non-empty).
      if (stack.empty()) {
        return false;
      }
      int closePos = code.find("]]>", i + 9);
      if (closePos == std::string::npos) {
        return false;
      }
      i = closePos + 3;
      continue;
    }

    // Start tag: <NAME>
    // If the single top-level tag already closed, no more tags are allowed.
    if (topLevelClosed) {
      return false;
    }
    int j = i + 1;
    std::string name;
    while (j < n && code[j] != '>') {
      name.push_back(code[j]);
      ++j;
    }
    if (j >= n) {
      // no closing '>' -> unmatched '<'
      return false;
    }
    ++j;  // skip '>'
    if (!IsValidTagName(name)) {
      return false;
    }
    stack.push_back(name);
    i = j;
  }

  // All tags must be properly closed (and the code must have ended exactly
  // after the single top-level tag was closed).
  return topLevelClosed && stack.empty();
}

TagValidatorSolution::TagValidatorSolution() {
  setMetaInfo({.id = 591,
               .title = "Tag Validator",
               .url = "https://leetcode.com/problems/tag-validator/"});
  registerStrategy({.name = "StackScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Stack"}},
                   &isValidImpl);
}

bool TagValidatorSolution::isValid(const std::string& code) {
  return getSolution()(code);
}

}  // namespace problem_591
}  // namespace leetcode
