#include "leetcode/problems/design-sql.h"

#include <algorithm>

namespace leetcode {
namespace problem_2408 {

SQL::SQL(std::vector<std::string>& names, std::vector<int>& columns) {
  for (std::size_t i = 0; i < names.size(); ++i) {
    Table t;
    t.columns = columns[i];
    t.nextId = 1;
    tables_[names[i]] = t;
  }
}

bool SQL::ins(std::string name, std::vector<std::string> row) {
  auto it = tables_.find(name);
  if (it == tables_.end()) return false;
  if (static_cast<int>(row.size()) != it->second.columns) return false;

  int id = it->second.nextId++;
  it->second.rows[id] = std::move(row);
  return true;
}

void SQL::rmv(std::string name, int rowId) {
  auto it = tables_.find(name);
  if (it == tables_.end()) return;
  it->second.rows.erase(rowId);
}

std::string SQL::sel(std::string name, int rowId, int columnId) {
  auto it = tables_.find(name);
  if (it == tables_.end()) return "<null>";
  auto& table = it->second;
  auto rowIt = table.rows.find(rowId);
  if (rowIt == table.rows.end()) return "<null>";
  if (columnId < 1 || columnId > static_cast<int>(rowIt->second.size()))
    return "<null>";
  return rowIt->second[columnId - 1];
}

std::vector<std::string> SQL::exp(std::string name) {
  auto it = tables_.find(name);
  if (it == tables_.end()) return {};

  auto& table = it->second;
  std::vector<int> ids;
  ids.reserve(table.rows.size());
  for (const auto& kv : table.rows) {
    ids.push_back(kv.first);
  }
  std::sort(ids.begin(), ids.end());

  std::vector<std::string> result;
  result.reserve(ids.size());
  for (int id : ids) {
    const auto& row = table.rows.at(id);
    std::string line = std::to_string(id);
    for (const auto& col : row) {
      line += "," + col;
    }
    result.push_back(std::move(line));
  }
  return result;
}

}  // namespace problem_2408
}  // namespace leetcode
