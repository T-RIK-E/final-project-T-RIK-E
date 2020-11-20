//
// Created by rtera on 11/19/2020.
//

#include <core/selection_sort.h>

#include <utility>

namespace sorting {
SelectionSort::SelectionSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  i_ = 0;
  j_ = i_ + 1;
}

void SelectionSort::SortOneStep() {
  // One by one move boundary of unsorted subarray
  if (i_ < unsorted_list_.size() - 1) {
    // Find the minimum element in unsorted array
    min_idx_ = i_;
    if (j_ < unsorted_list_.size()) {
      if (unsorted_list_[j_] < unsorted_list_[min_idx_]) {
        min_idx_ = j_;
      }
    }

    /**
    // Swap the found minimum element with the first element
    swap(&arr[min_idx_], &arr[i_]);
     **/
  }
}
}  // namespace sorting