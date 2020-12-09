#include <core/insertion_sort.h>

#include <utility>

namespace sorting {
InsertionSort::InsertionSort() : Sort() {
  name_ = "Insertion Sort";
  i_ = 1;
  j_ = i_ - 1;
}
InsertionSort::InsertionSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Insertion Sort";
  i_ = 1;
  j_ = i_ - 1;
}

void InsertionSort::SortOneStep() {
  if (i_ < static_cast<int>(unsorted_list_.size())) {
    if (j_ >= 0 && unsorted_list_[j_] > unsorted_list_[j_+1]) {
      access_++;
      height1_ = unsorted_list_[j_+1];
      height2_ = unsorted_list_[j_];
      swap(unsorted_list_[j_+1], unsorted_list_[j_]);
      j_--;
    } else if (i_ < static_cast<int>(unsorted_list_.size())-1) {
      i_++;
      j_ = i_ - 1;
    }
  }
}
}  // namespace sorting