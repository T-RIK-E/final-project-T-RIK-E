#include <core/sort.h>

#include <utility>

namespace sorting {
Sort::Sort(std::vector<size_t> unsorted_list)
    : unsorted_list_(std::move(unsorted_list)) {}

const std::vector<size_t>& Sort::GetUnsortedList() const {
  return unsorted_list_;
}
}  // namespace sorting