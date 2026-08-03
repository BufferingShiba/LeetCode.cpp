#ifndef LEETCODE_PROBLEMS_DESIGN_RIDE_SHARING_SYSTEM_H_
#define LEETCODE_PROBLEMS_DESIGN_RIDE_SHARING_SYSTEM_H_

#include <queue>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_3829 {

class RideSharingSystem {
 public:
  RideSharingSystem() = default;

  void addRider(int riderId);
  void addDriver(int driverId);
  std::vector<int> matchDriverWithRider();
  void cancelRider(int riderId);

 private:
  std::queue<int> drivers_;
  std::queue<int> riders_;
  std::unordered_set<int> valid_riders_;
};

}  // namespace problem_3829
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_RIDE_SHARING_SYSTEM_H_
