#include "leetcode/problems/utf-8-validation.h"

namespace leetcode {
namespace problem_393 {

static bool solution1(vector<int>& data) {
  int i = 0;
  int n = static_cast<int>(data.size());
  while (i < n) {
    int first = data[i];
    int byte_count;
    // Count leading 1 bits.
    if ((first & 0x80) == 0) {
      byte_count = 1;
    } else if ((first & 0xE0) == 0xC0) {
      byte_count = 2;
    } else if ((first & 0xF0) == 0xE0) {
      byte_count = 3;
    } else if ((first & 0xF8) == 0xF0) {
      byte_count = 4;
    } else {
      // Leading bits are 10xxxxxx or 11111xxx -> invalid.
      return false;
    }
    // Not enough bytes remaining.
    if (i + byte_count > n) {
      return false;
    }
    // Validate the continuation bytes.
    for (int j = i + 1; j < i + byte_count; ++j) {
      if ((data[j] & 0xC0) != 0x80) {
        return false;
      }
    }
    i += byte_count;
  }
  return true;
}

Utf8ValidationSolution::Utf8ValidationSolution() {
  setMetaInfo({
      .id = 393,
      .title = "UTF-8 Validation",
      .url = "https://leetcode.com/problems/utf-8-validation"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

bool Utf8ValidationSolution::validUtf8(vector<int>& data) {
  return getSolution()(data);
}

}  // namespace problem_393
}  // namespace leetcode
