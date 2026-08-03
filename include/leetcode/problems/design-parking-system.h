#ifndef LEETCODE_PROBLEMS_1603_DESIGN_PARKING_SYSTEM_H__
#define LEETCODE_PROBLEMS_1603_DESIGN_PARKING_SYSTEM_H__

namespace leetcode::problem_1603 {

// 题目要求实现的停车场类
class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small);
  bool addCar(int carType);

 private:
  int big_;
  int medium_;
  int small_;
};

// 测试框架基类（虚接口）
class DesignParkingSystem {
 public:
  virtual ~DesignParkingSystem() = default;
  virtual bool addCar(int carType) = 0;
};

// 测试框架派生类，持有具体实现并转发
class DesignParkingSystemSolution : public DesignParkingSystem {
 public:
  DesignParkingSystemSolution(int big, int medium, int small);
  bool addCar(int carType) override;

 private:
  ParkingSystem impl_;
};

}  // namespace leetcode::problem_1603

#endif  // LEETCODE_PROBLEMS_1603_DESIGN_PARKING_SYSTEM_H__
