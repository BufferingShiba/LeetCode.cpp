#ifndef LEETCODE_PROBLEMS_DESIGN_SQL_H
#define LEETCODE_PROBLEMS_DESIGN_SQL_H

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2408 {

class SQL {
 public:
  SQL(std::vector<std::string>& names, std::vector<int>& columns);

  bool ins(std::string name, std::vector<std::string> row);
  void rmv(std::string name, int rowId);
  std::string sel(std::string name, int rowId, int columnId);
  std::vector<std::string> exp(std::string name);

 private:
  struct Table {
    int columns;
    int nextId;
    std::unordered_map<int, std::vector<std::string>> rows;
  };
  std::unordered_map<std::string, Table> tables_;
};

}  // namespace problem_2408
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_SQL_H
