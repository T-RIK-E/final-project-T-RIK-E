#include <core/insertion_sort.h>

#include <utility>

namespace sorting {
InsertionSort::InsertionSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  i_ = 1;
  key_ = unsorted_list_[i_];
  j_ = i_ - 1;
}

void InsertionSort::SortOneStep() {
  if (i_ < static_cast<int>(unsorted_list_.size())) {
    height1_ = unsorted_list_[i_];
    if (j_ >= 0 && static_cast<int>(unsorted_list_[j_]) > key_) {
      unsorted_list_[j_ + 1] = unsorted_list_[j_];
      unsorted_list_[j_] = key_;
      height2_ = unsorted_list_[j_];
      j_--;
    } else if (i_ < static_cast<int>(unsorted_list_.size())-1) {
      i_++;
      key_ = unsorted_list_[i_];
      j_ = i_ - 1;
    }
  }
}
}  // namespace sorting