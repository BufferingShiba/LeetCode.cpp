#include "leetcode/problems/design-ride-sharing-system.h"

namespace leetcode {
namespace problem_3829 {

void RideSharingSystem::addRider(int riderId) {
  riders_.push(riderId);
  valid_riders_.insert(riderId);
}

void RideSharingSystem::addDriver(int driverId) {
  drivers_.push(driverId);
}

std::vector<int> RideSharingSystem::matchDriverWithRider() {
  // Skip cancelled riders at the front of the queue
  while (!riders_.empty() &&
         valid_riders_.find(riders_.front()) == valid_riders_.end()) {
    riders_.pop();
  }

  if (drivers_.empty() || riders_.empty()) {
    return {-1, -1};
  }

  int driverId = drivers_.front();
  drivers_.pop();

  int riderId = riders_.front();
  riders_.pop();
  valid_riders_.erase(riderId);

  return {driverId, riderId};
}

void RideSharingSystem::cancelRider(int riderId) {
  valid_riders_.erase(riderId);
}

}  // namespace problem_3829
}  // namespace leetcode
