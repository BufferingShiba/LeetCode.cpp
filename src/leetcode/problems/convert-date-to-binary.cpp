#include "leetcode/problems/convert-date-to-binary.h"

#include <bitset>
#include <sstream>
#include <stdexcept>
#include <string>

namespace leetcode {
namespace problem_3280 {

namespace {

std::string toBinaryWithoutLeadingZeros(int value) {
  if (value == 0) {
    return "0";
  }
  std::string result;
  while (value > 0) {
    result.insert(result.begin(), static_cast<char>('0' + (value & 1)));
    value >>= 1;
  }
  return result;
}

std::string convertDateToBinaryImpl(const std::string& date) {
  std::string year = date.substr(0, 4);
  std::string month = date.substr(5, 2);
  std::string day = date.substr(8, 2);

  std::ostringstream oss;
  oss << toBinaryWithoutLeadingZeros(std::stoi(year)) << '-'
      << toBinaryWithoutLeadingZeros(std::stoi(month)) << '-'
      << toBinaryWithoutLeadingZeros(std::stoi(day));
  return oss.str();
}

}  // namespace

ConvertDateToBinarySolution::ConvertDateToBinarySolution() {
  setMetaInfo({.id = 3280,
               .title = "Convert Date to Binary",
               .url =
                   "https://leetcode.com/problems/convert-date-to-binary/"});
  registerStrategy(
      {.name = "math-bitshift",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String"}},
      convertDateToBinaryImpl);
}

std::string ConvertDateToBinarySolution::convertDateToBinary(
    std::string date) {
  return getSolution()(date);
}

}  // namespace problem_3280
}  // namespace leetcode
