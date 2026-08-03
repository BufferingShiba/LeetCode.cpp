#include "leetcode/problems/shortest-uncommon-substring-in-an-array.h"

#include <algorithm>

namespace leetcode {
namespace problem_3076 {

static vector<string> solution1(vector<string>& arr) {
  int n = (int)arr.size();
  vector<string> answer;
  answer.reserve(n);

  for (int i = 0; i < n; ++i) {
    const string& s = arr[i];
    // Collect all distinct substrings of s.
    vector<string> subs;
    for (int len = 1; len <= (int)s.size(); ++len) {
      for (int start = 0; start + len <= (int)s.size(); ++start) {
        subs.push_back(s.substr(start, len));
      }
    }
    // Sort by (length, lexicographic) so first valid is the answer.
    std::sort(subs.begin(), subs.end(),
              [](const string& a, const string& b) {
                if (a.size() != b.size()) return a.size() < b.size();
                return a < b;
              });

    string result;
    for (const string& sub : subs) {
      bool foundElsewhere = false;
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        if (arr[j].find(sub) != string::npos) {
          foundElsewhere = true;
          break;
        }
      }
      if (!foundElsewhere) {
        result = sub;
        break;
      }
    }
    answer.push_back(result);
  }
  return answer;
}

ShortestUncommonSubstringInAnArraySolution::ShortestUncommonSubstringInAnArraySolution() {
  setMetaInfo({
      .id = 3076,
      .title = "Shortest Uncommon Substring in an Array",
      .url = "https://leetcode.com/problems/shortest-uncommon-substring-in-an-array"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

vector<string> ShortestUncommonSubstringInAnArraySolution::shortestSubstrings(vector<string>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_3076
}  // namespace leetcode
