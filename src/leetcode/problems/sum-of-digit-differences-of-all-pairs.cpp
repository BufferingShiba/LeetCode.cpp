#include "leetcode/problems/sum-of-digit-differences-of-all-pairs.h"

#include <algorithm>
#include <array>

namespace {

long long sumDigitDifferencesImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    long long total_pairs = 1LL * n * (n - 1) / 2;

    long long result = 0;
    int divisor = 1;
    int remaining = nums[0];

    while (remaining > 0) {
        std::array<int, 10> count{};
        for (int num : nums) {
            ++count[(num / divisor) % 10];
        }

        long long same = 0;
        for (int d = 0; d < 10; ++d) {
            long long c = count[d];
            same += c * (c - 1) / 2;
        }

        result += total_pairs - same;

        divisor *= 10;
        remaining /= 10;
    }

    return result;
}

}  // namespace

namespace leetcode {
namespace problem_3153 {

SumOfDigitDifferencesOfAllPairsSolution::SumOfDigitDifferencesOfAllPairsSolution() {
    setMetaInfo({.id = 3153,
                 .title = "Sum of Digit Differences of All Pairs",
                 .url = "https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/"});
    registerStrategy({.name = "position_counting",
                      .expected = "Accepted",
                      .time_complexity = "O(n*d)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Hash Table", "Math", "Counting"}},
                     sumDigitDifferencesImpl);
}

long long SumOfDigitDifferencesOfAllPairsSolution::sumDigitDifferences(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_3153
}  // namespace leetcode
