#include <core/comb_sort.h>

namespace sorting {
CombSort::CombSort() : Sort(){
  name_ = "Comb Sort";
  gap_ = unsorted_list_.size();
  swapped_ = false;
  go_ = true;
  i_ = 0;
}
CombSort::CombSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Comb Sort";
  gap_ = unsorted_list_.size();
  swapped_ = false;
  go_ = true;
  i_ = 0;
}

void CombSort::SortOneStep() {
  // Keep running while gap is more than 1 and last
  // iteration caused a swap
  if (gap_ != 1 || go_)
  {
    // Compare all elements with current gap
    if (i_<unsorted_list_.size()-gap_)
    {
      height1_ = unsorted_list_[i_];
      height2_ = unsorted_list_[i_+gap_];
      // Swap if larger is ahead of smaller number
      if (unsorted_list_[i_] > unsorted_list_[i_+gap_])
      {
        swap(unsorted_list_[i_], unsorted_list_[i_+gap_]);
        // Set swap to true
        swapped_ = true;
      }
      // Increase array access and increment i
      access_ += 2;
      i_++;

    // After looping through with gap, if gap is 1 and there were no swaps,
    // end the sort
    } else if (gap_ == 1 && !swapped_) {
      go_ = false;
    // Else, repeat the sort with a different gap.
    } else {
      swapped_ = false;
      i_ = 0;
      GetNextGap();
    }
  }
}

void CombSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  access_ = 0;
  gap_ = unsorted_list_.size();
  swapped_ = false;
  go_ = true;
  i_ = 0;
}

void CombSort::GetNextGap() {
  // Decrease the gap by the most optimal factor. This is a constant found by
  // researchers.
  gap_ = (gap_*10)/13;

  // If the decreased gap is a decimal, set the gap to 1.
  if (gap_ < 1) {
    gap_ =  1;
  }
}
}  // namespace sorting