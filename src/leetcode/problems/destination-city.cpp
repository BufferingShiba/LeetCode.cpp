#include "leetcode/problems/destination-city.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_1436 {

static std::string destCityImpl(std::vector<std::vector<std::string>>& paths) {
  std::unordered_set<std::string> outgoing;
  for (const auto& p : paths) {
    outgoing.insert(p[0]);
  }
  for (const auto& p : paths) {
    if (outgoing.find(p[1]) == outgoing.end()) {
      return p[1];
    }
  }
  return {};  // unreachable per problem constraints
}

DestinationCitySolution::DestinationCitySolution() {
  setMetaInfo({.id = 1436, .title = "Destination City",
               .url = "https://leetcode.com/problems/destination-city/"});
  registerStrategy(
      {.name = "HashSet",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "String"}},
      destCityImpl);
}

std::string DestinationCitySolution::destCity(
    std::vector<std::vector<std::string>>& paths) {
  return getSolution()(paths);
}

}  // namespace problem_1436
}  // namespace leetcode
