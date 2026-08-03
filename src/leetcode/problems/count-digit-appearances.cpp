#include "leetcode/problems/count-digit-appearances.h"

namespace leetcode::problem_3895 {

namespace {

int countDigitOccurrencesImpl(std::vector<int>& nums, int digit) {
    int total = 0;
    for (int num : nums) {
        while (num > 0) {
            if (num % 10 == digit) {
                ++total;
            }
            num /= 10;
        }
    }
    return total;
}

}  // namespace

CountDigitAppearancesSolution::CountDigitAppearancesSolution() {
    setMetaInfo({.id = 3895,
                 .title = "Count Digit Appearances",
                 .url =
                     "https://leetcode.com/problems/count-digit-appearances/"});
    registerStrategy(
        {.name = "iterative-modulo",
         .expected = "Accepted",
         .time_complexity = "O(n * digits)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Math"}},
        countDigitOccurrencesImpl);
}

int CountDigitAppearancesSolution::countDigitOccurrences(
    std::vector<int>& nums, int digit) {
    return getSolution()(nums, digit);
}

}  // namespace leetcode::problem_3895
