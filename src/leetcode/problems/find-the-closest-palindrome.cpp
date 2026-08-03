#include "leetcode/problems/find-the-closest-palindrome.h"

#include <algorithm>
#include <cmath>
#include <set>
#include <string>

namespace leetcode {
namespace problem_564 {

namespace {

// 用数值 p 构造一个回文：p + reverse(p 去掉最后一位)。
// p 视为回文的前半（含中心）。
std::string normalize(std::string value) {
  const auto first = value.find_first_not_of('0');
  if (first == std::string::npos) return "0";
  return value.substr(first);
}

long long makePalindrome(const std::string& prefix, int originalLength) {
  const int mirrored = std::min(
      originalLength / 2, static_cast<int>(prefix.size()));
  std::string result = prefix;
  for (int i = mirrored - 1; i >= 0; --i) result += prefix[i];
  return std::stoll(normalize(std::move(result)));
}

long long pow10(int e) {
  long long r = 1;
  for (int i = 0; i < e; ++i) r *= 10;
  return r;
}

std::string nearestPalindromicImpl(std::string n) {
  const int len = static_cast<int>(n.size());
  const long long num = std::stoll(n);

  // 候选集合：上界 100..001，下界全 9，以及基于前半部分 ±1/自身构造的回文。
  std::set<long long> cand;
  cand.insert(pow10(len) + 1);           // 形如 100..001
  cand.insert(pow10(len - 1) - 1);       // len-1 位全 9（len=1 时为 0）

  const int prefixLength = (len + 1) / 2;
  const long long half = std::stoll(n.substr(0, prefixLength));
  for (long long d : {half - 1, half, half + 1}) {
    const std::string prefix = std::to_string(d);
    if (static_cast<int>(prefix.size()) <= prefixLength) {
      cand.insert(makePalindrome(prefix, len));
    }
  }

  cand.erase(num);  // 排除自身

  long long best = -1;
  long long bestDiff = 0;
  for (long long c : cand) {
    long long diff = std::llabs(c - num);
    if (best == -1 || diff < bestDiff ||
        (diff == bestDiff && c < best)) {
      best = c;
      bestDiff = diff;
    }
  }

  return std::to_string(best);
}

}  // namespace

std::string FindTheClosestPalindromeSolution::nearestPalindromic(std::string n) {
  return getSolution()(std::move(n));
}

void FindTheClosestPalindromeSolution::registerStrategies() {
  registerStrategy(
      {.name = "MirrorConstruction",
       .expected = "Accepted",
       .time_complexity = "O(len)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String"}},
      nearestPalindromicImpl);
}

}  // namespace problem_564
}  // namespace leetcode
