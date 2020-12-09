//
// Created by rtera on 11/19/2020.
//

#include <core/selection_sort.h>

namespace sorting {
SelectionSort::SelectionSort() : Sort() {
  name_ = "Selection Sort";
  i_ = 0;
  min_idx_ = i_;
  j_ = i_ + 1;
}
SelectionSort::SelectionSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Selection Sort";
  i_ = 0;
  min_idx_ = i_;
  j_ = i_ + 1;
}

void SelectionSort::SortOneStep() {
  // One by one move boundary of unsorted subarray
  if (i_ < static_cast<int>(unsorted_list_.size()) - 1) {
    height1_ = unsorted_list_[min_idx_];
    // Find the minimum element in unsorted array
    if (j_ < static_cast<int>(unsorted_list_.size())) {
      height2_ = unsorted_list_[j_];
      if (unsorted_list_[j_] < unsorted_list_[min_idx_]) {
        access_+=2;
        min_idx_ = j_;
      }
      j_++;
    } else {
      swap(unsorted_list_[i_], unsorted_list_[min_idx_]);
      i_++;
      min_idx_ = i_;
      j_ = i_ + 1;
    }
  }
}

void SelectionSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  i_ = 0;
  min_idx_ = i_;
  j_ = i_ + 1;

}
}  // namespace sorting