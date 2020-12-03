#include <core/bubble_sort.h>

namespace sorting {
BubbleSort::BubbleSort(std::vector<size_t> unsorted_list) :
      Sort(std::move(unsorted_list)) {
  name_ = "Bubble Sort";
  i_ = 0;
  j_ = 0;
}

void BubbleSort::SortOneStep() {

  if (i_ < static_cast<int>(unsorted_list_.size())-1) {
    // Last i elements are already in place
    if (j_ < static_cast<int>(unsorted_list_.size())-i_-1) {
      height1_ = unsorted_list_[j_];
      height2_ = unsorted_list_[j_+1];
      if (unsorted_list_[j_] > unsorted_list_[j_+1]) {
        int temp = unsorted_list_[j_];
        unsorted_list_[j_] = unsorted_list_[j_+1];
        unsorted_list_[j_ + 1] = temp;
      }
      j_++;
    } else {
      i_++;
      j_ = 0;
    }
  }
}
}