#include "leetcode/problems/number-of-changing-keys.h"

namespace leetcode {
namespace problem_3019 {

namespace {

int countKeyChangesImpl(std::string s) {
  int changes = 0;
  for (size_t i = 1; i < s.size(); ++i) {
    if (std::tolower(static_cast<unsigned char>(s[i])) !=
        std::tolower(static_cast<unsigned char>(s[i - 1]))) {
      ++changes;
    }
  }
  return changes;
}

}  // namespace

NumberOfChangingKeysSolution::NumberOfChangingKeysSolution() {
  setMetaInfo({.id = 3019,
               .title = "Number of Changing Keys",
               .url = "https://leetcode.com/problems/number-of-changing-keys/"});
  registerStrategy({.name = "single-pass-lowercase-compare",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"}},
                   countKeyChangesImpl);
}

int NumberOfChangingKeysSolution::countKeyChanges(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3019
}  // namespace leetcode
