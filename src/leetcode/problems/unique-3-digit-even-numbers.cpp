#include "leetcode/problems/unique-3-digit-even-numbers.h"

#include <unordered_set>

namespace leetcode::problem_3483 {

namespace {

int totalNumbersImpl(std::vector<int>& digits) {
    const int n = static_cast<int>(digits.size());
    std::unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        if (digits[i] == 0) continue;  // 百位不能为 0
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                if (digits[k] % 2 != 0) continue;  // 个位必须为偶数
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                seen.insert(num);
            }
        }
    }
    return static_cast<int>(seen.size());
}

}  // namespace

Unique3DigitEvenNumbersSolution::Unique3DigitEvenNumbersSolution() {
    setMetaInfo({.id = 3483,
                 .title = "Unique 3-Digit Even Numbers",
                 .url = "https://leetcode.com/problems/unique-3-digit-even-numbers/"});
    registerStrategy({.name = "enumeration-with-set",
                      .expected = "Accepted",
                      .time_complexity = "O(n^3)",
                      .space_complexity = "O(#distinct_nums)",
                      .tags = {"Array", "Hash Table", "Enumeration"}},
                     totalNumbersImpl);
}

int Unique3DigitEvenNumbersSolution::totalNumbers(std::vector<int>& digits) {
    return getSolution()(digits);
}

}  // namespace leetcode::problem_3483
