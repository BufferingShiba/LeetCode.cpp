#include "leetcode/problems/process-string-with-special-operations-i.h"

#include <algorithm>

namespace leetcode {
namespace problem_3612 {

static string solution1(string s) {
  string result;
  for (char c : s) {
    if (c == '*') {
      if (!result.empty()) result.pop_back();
    } else if (c == '#') {
      result += result;
    } else if (c == '%') {
      std::reverse(result.begin(), result.end());
    } else {
      result.push_back(c);
    }
  }
  return result;
}

ProcessStringWithSpecialOperationsISolution::ProcessStringWithSpecialOperationsISolution() {
  setMetaInfo({
      .id = 3612,
      .title = "Process String with Special Operations I",
      .url = "https://leetcode.com/problems/process-string-with-special-operations-i"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

string ProcessStringWithSpecialOperationsISolution::processStr(string s) {
  return getSolution()(s);
}

}  // namespace problem_3612
}  // namespace leetcode
