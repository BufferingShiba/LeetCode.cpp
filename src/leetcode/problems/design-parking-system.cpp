#include "leetcode/problems/design-parking-system.h"

namespace leetcode::problem_1603 {

ParkingSystem::ParkingSystem(int big, int medium, int small)
    : big_(big), medium_(medium), small_(small) {}

bool ParkingSystem::addCar(int carType) {
  if (carType == 1) {  // big
    if (big_ == 0) {
      return false;
    }
    --big_;
    return true;
  }
  if (carType == 2) {  // medium
    if (medium_ == 0) {
      return false;
    }
    --medium_;
    return true;
  }
  // carType == 3, small
  if (small_ == 0) {
    return false;
  }
  --small_;
  return true;
}

DesignParkingSystemSolution::DesignParkingSystemSolution(int big, int medium,
                                                         int small)
    : impl_(big, medium, small) {}

bool DesignParkingSystemSolution::addCar(int carType) {
  return impl_.addCar(carType);
}

}  // namespace leetcode::problem_1603
