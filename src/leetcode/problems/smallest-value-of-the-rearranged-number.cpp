#include "leetcode/problems/smallest-value-of-the-rearranged-number.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_2165 {

static long long smallestNumberImpl(long long num) {
    if (num == 0) return 0;

    bool negative = num < 0;
    std::string s = std::to_string(negative ? -num : num);

    if (negative) {
        // 负数：降序排列 → 绝对值最大 → 值最小
        std::sort(s.begin(), s.end(), std::greater<char>());
    } else {
        // 正数：升序排列，若首位为 0 则把第一个非零换到首位
        std::sort(s.begin(), s.end());
        if (s[0] == '0') {
            for (size_t i = 1; i < s.size(); ++i) {
                if (s[i] != '0') {
                    std::swap(s[0], s[i]);
                    break;
                }
            }
        }
    }

    long long result = std::stoll(s);
    return negative ? -result : result;
}

SmallestValueOfTheRearrangedNumberSolution::SmallestValueOfTheRearrangedNumberSolution() {
    setMetaInfo({.id = 2165,
                 .title = "Smallest Value of the Rearranged Number",
                 .url = "https://leetcode.com/problems/smallest-value-of-the-rearranged-number/"});
    registerStrategy({.name = "Sorting",
                      .expected = "Accepted",
                      .time_complexity = "O(d log d)",
                      .space_complexity = "O(d)",
                      .tags = {"Math", "Sorting"}},
                     smallestNumberImpl);
}

long long SmallestValueOfTheRearrangedNumberSolution::smallestNumber(long long num) {
    return getSolution()(num);
}

}  // namespace problem_2165
}  // namespace leetcode
