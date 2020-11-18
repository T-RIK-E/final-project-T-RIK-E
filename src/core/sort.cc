#include <core/sort.h>

namespace sorting {
Sort::Sort(std::vector<size_t> unsorted_list)
    : unsorted_list_(unsorted_list) {}

const std::vector<size_t>& Sort::GetUnsortedList() const {
  return unsorted_list_;
}
}  // namespace sorting