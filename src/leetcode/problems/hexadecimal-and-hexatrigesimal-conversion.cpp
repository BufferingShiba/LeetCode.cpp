#include "leetcode/problems/hexadecimal-and-hexatrigesimal-conversion.h"

#include <string>

namespace leetcode {
namespace problem_3602 {
namespace {

const char* kDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string toBase(unsigned long long value, int base) {
  if (value == 0) {
    return "0";
  }
  std::string result;
  while (value > 0) {
    result.push_back(kDigits[value % base]);
    value /= base;
  }
  // reverse
  for (size_t i = 0, j = result.size() - 1; i < j; ++i, --j) {
    std::swap(result[i], result[j]);
  }
  return result;
}

std::string concatHex36Impl(int n) {
  unsigned long long square = static_cast<unsigned long long>(n) * n;
  unsigned long long cube = square * n;
  return toBase(square, 16) + toBase(cube, 36);
}

}  // namespace

HexadecimalAndHexatrigesimalConversionSolution::
    HexadecimalAndHexatrigesimalConversionSolution() {
  setMetaInfo({.id = 3602,
               .title = "Hexadecimal and Hexatrigesimal Conversion",
               .url = "https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/"});
  registerStrategy({.name = "BaseConversion",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Math", "String"}},
                   concatHex36Impl);
}

std::string HexadecimalAndHexatrigesimalConversionSolution::concatHex36(
    int n) {
  return getSolution()(n);
}

}  // namespace problem_3602
}  // namespace leetcode
