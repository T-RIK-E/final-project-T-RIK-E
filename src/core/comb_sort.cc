#include <core/comb_sort.h>

namespace sorting {
CombSort::CombSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Comb Sort";
  gap_ = unsorted_list_.size();
  swapped_ = false;
  go_ = true;
  i_ = 0;
}

void CombSort::SortOneStep() {
  // Initialize swapped as true to make sure that
  // loop runs

  // Keep running while gap is more than 1 and last
  // iteration caused a swap
  if (gap_ != 1 || go_)
  {
    // Compare all elements with current gap
    if (i_<unsorted_list_.size()-gap_)
    {
      height1_ = unsorted_list_[i_];
      height2_ = unsorted_list_[i_+gap_];
      if (unsorted_list_[i_] > unsorted_list_[i_+gap_])
      {
        swap(unsorted_list_[i_], unsorted_list_[i_+gap_]);
        swapped_ = true;
      }
      i_++;
    } else if (gap_ == 1 && !swapped_) {
      go_ = false;
    } else {
      swapped_ = false;
      i_ = 0;
      GetNextGap();
    }
  }
}

void CombSort::GetNextGap() {
  gap_ = (gap_*10)/13;

  if (gap_ < 1) {
    gap_ =  1;
  }
}
}  // namespace sorting