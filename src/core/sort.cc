#include <core/sort.h>

#include <utility>

namespace sorting {
Sort::Sort(std::vector<size_t> unsorted_list)
    : unsorted_list_(std::move(unsorted_list)) {}

Sort::~Sort() = default;

const std::vector<size_t>& Sort::GetUnsortedList() const {
  return unsorted_list_;
}

const size_t Sort::GetHeight1() const {
  return height1_;
}

const size_t Sort::GetHeight2() const {
  return height2_;
}
}  // namespace sorting