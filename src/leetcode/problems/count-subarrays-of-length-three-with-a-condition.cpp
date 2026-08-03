#include "leetcode/problems/count-subarrays-of-length-three-with-a-condition.h"

namespace leetcode::problem_3392 {

static int countSubarraysImpl(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int count = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
            ++count;
        }
    }
    return count;
}

CountSubarraysOfLengthThreeWithAConditionSolution::CountSubarraysOfLengthThreeWithAConditionSolution() {
    setMetaInfo({.id = 3392,
                 .title = "Count Subarrays of Length Three With a Condition",
                 .url = "https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/"});
    registerStrategy({.name = "LinearScan",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Enumeration"}},
                     countSubarraysImpl);
}

int CountSubarraysOfLengthThreeWithAConditionSolution::countSubarrays(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace leetcode::problem_3392
