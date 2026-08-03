#include "leetcode/problems/restore-ip-addresses.h"

namespace leetcode {
namespace problem_93 {

namespace {

bool validSegment(const std::string& s, int start, int end) {
  // segment: s[start, end) as an octet (1-3 digits)
  int len = end - start;
  if (len == 0 || len > 3) return false;
  // leading zero not allowed unless it is a single "0"
  if (len > 1 && s[start] == '0') return false;
  int value = 0;
  for (int i = start; i < end; ++i) {
    value = value * 10 + (s[i] - '0');
  }
  return value <= 255;
}

void dfs(const std::string& s, int start, int segments,
         std::vector<std::string>& parts, std::vector<std::string>& result) {
  if (segments == 4) {
    if (start == static_cast<int>(s.size())) {
      result.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
    }
    return;
  }
  // Each segment must be 1-3 digits.
  for (int len = 1; len <= 3; ++len) {
    int end = start + len;
    if (end > static_cast<int>(s.size())) break;
    if (!validSegment(s, start, end)) continue;
    parts.push_back(s.substr(start, len));
    dfs(s, end, segments + 1, parts, result);
    parts.pop_back();
  }
}

}  // namespace

static std::vector<std::string> solution1(std::string s) {
  std::vector<std::string> result;
  if (s.size() < 4 || s.size() > 12) return result;
  std::vector<std::string> parts;
  dfs(s, 0, 0, parts, result);
  return result;
}

RestoreIpAddressesSolution::RestoreIpAddressesSolution() {
  setMetaInfo({
      .id = 93,
      .title = "Restore IP Addresses",
      .url = "https://leetcode.com/problems/restore-ip-addresses/"
  });
  registerStrategy({.name = "DFS Backtracking"}, solution1);
}

std::vector<std::string> RestoreIpAddressesSolution::restoreIpAddresses(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_93
}  // namespace leetcode
