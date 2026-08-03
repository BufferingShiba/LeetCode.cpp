#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-students-unable-to-eat-lunch.h"

namespace leetcode {
namespace problem_1700 {

class NumberOfStudentsUnableToEatLunchTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfStudentsUnableToEatLunchSolution solution_;
};

TEST_P(NumberOfStudentsUnableToEatLunchTest, Example1) {
  std::vector<int> students{1, 1, 0, 0};
  std::vector<int> sandwiches{0, 1, 0, 1};
  EXPECT_EQ(0, solution_.countStudents(students, sandwiches));
}

TEST_P(NumberOfStudentsUnableToEatLunchTest, Example2) {
  std::vector<int> students{1, 1, 1, 0, 0, 1};
  std::vector<int> sandwiches{1, 0, 0, 0, 1, 1};
  EXPECT_EQ(3, solution_.countStudents(students, sandwiches));
}

TEST_P(NumberOfStudentsUnableToEatLunchTest, SelfAuthoredAllMatch) {
  std::vector<int> students{0, 1, 0, 1};
  std::vector<int> sandwiches{0, 0, 1, 1};
  EXPECT_EQ(0, solution_.countStudents(students, sandwiches));
}

TEST_P(NumberOfStudentsUnableToEatLunchTest, SelfAuthoredNoneAtFront) {
  std::vector<int> students{1, 1, 1};
  std::vector<int> sandwiches{0, 0, 0};
  EXPECT_EQ(3, solution_.countStudents(students, sandwiches));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfStudentsUnableToEatLunchTests,
    NumberOfStudentsUnableToEatLunchTest,
    ::testing::ValuesIn(NumberOfStudentsUnableToEatLunchSolution()
                            .getStrategyNames()));

}  // namespace problem_1700
}  // namespace leetcode
