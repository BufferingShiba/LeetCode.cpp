#include "leetcode/problems/split-array-into-fibonacci-sequence.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_842 {
namespace {

constexpr long long kInt32Limit = (1LL << 31);

// 判断 s 的子串 [start, end) 是否合法：无多余前导零，且能解析为 32 位有符号数。
bool isValidNumber(const std::string& s, int start, int end, long long& out) {
  if (end <= start) return false;
  if (s[start] == '0' && end - start > 1) return false;  // 前导零不合法
  long long val = 0;
  for (int i = start; i < end; ++i) {
    val = val * 10 + (s[i] - '0');
    if (val >= kInt32Limit) return false;
  }
  out = val;
  return true;
}

std::vector<int> splitIntoFibonacciImpl(std::string num) {
  const int n = static_cast<int>(num.size());
  // 枚举第一个与第二个数的结束位置 [0,i) 和 [i,j)。
  for (int i = 1; i < n; ++i) {
    long long a = 0;
    if (!isValidNumber(num, 0, i, a)) break;  // 第一个数前导零，无需再扩展
    for (int j = i + 1; j < n; ++j) {
      long long b = 0;
      if (!isValidNumber(num, i, j, b)) break;  // 第二个数前导零则后续更长也非法
      std::vector<int> seq;
      seq.push_back(static_cast<int>(a));
      seq.push_back(static_cast<int>(b));
      std::string remaining = num.substr(j);
      int pos = 0;
      bool ok = true;
      long long x = a, y = b;
      while (pos < static_cast<int>(remaining.size())) {
        long long z = x + y;
        if (z >= kInt32Limit) {
          ok = false;
          break;
        }
        std::string zs = std::to_string(z);
        if (remaining.compare(pos, zs.size(), zs) != 0) {
          ok = false;
          break;
        }
        seq.push_back(static_cast<int>(z));
        pos += static_cast<int>(zs.size());
        x = y;
        y = z;
      }
      if (ok && static_cast<int>(seq.size()) >= 3 &&
          pos == static_cast<int>(remaining.size())) {
        return seq;
      }
    }
  }
  return {};
}

}  // namespace

SplitArrayIntoFibonacciSequenceSolution::SplitArrayIntoFibonacciSequenceSolution() {
  setMetaInfo({.id = 842,
               .title = "Split Array into Fibonacci Sequence",
               .url = "https://leetcode.com/problems/split-array-into-fibonacci-sequence/"});
  registerStrategy(
      {.name = "backtracking-enum",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(n)",
       .tags = {"String", "Backtracking"},
       .notes = "枚举前两个数的分割位置，用斐波那契递推校验与构造序列"},
      splitIntoFibonacciImpl);
}

std::vector<int> SplitArrayIntoFibonacciSequenceSolution::splitIntoFibonacci(
    std::string num) {
  return getSolution()(num);
}

}  // namespace problem_842
}  // namespace leetcode
