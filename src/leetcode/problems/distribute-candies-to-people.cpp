#include "leetcode/problems/distribute-candies-to-people.h"

namespace leetcode::problem_1103 {

namespace {

std::vector<int> distributeCandiesImpl(int candies, int num_people) {
  std::vector<int> ans(num_people, 0);
  int index = 0;
  int gift = 1;
  while (candies > 0) {
    int take = std::min(gift, candies);
    ans[index] += take;
    candies -= take;
    index = (index + 1) % num_people;
    ++gift;
  }
  return ans;
}

}  // namespace

DistributeCandiesToPeopleSolution::DistributeCandiesToPeopleSolution() {
  setMetaInfo({.id = 1103,
               .title = "Distribute Candies to People",
               .url = "https://leetcode.com/problems/distribute-candies-to-people/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(num_people + sqrt(candies))",
       .space_complexity = "O(num_people)",
       .tags = {"Math", "Simulation"}},
      distributeCandiesImpl);
}

std::vector<int> DistributeCandiesToPeopleSolution::distributeCandies(int candies,
                                                                      int num_people) {
  return getSolution()(candies, num_people);
}

}  // namespace leetcode::problem_1103
