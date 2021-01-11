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
  // Loop through the entire array
  if (i_ < static_cast<int>(unsorted_list_.size())) {
    // Looping back from i if j is larger than j + 1
    if (j_ >= 0 && unsorted_list_[j_] > unsorted_list_[j_+1]) {
      access_++;
      height1_ = unsorted_list_[j_+1];
      height2_ = unsorted_list_[j_];
      // Swap the two positions
      swap(unsorted_list_[j_+1], unsorted_list_[j_]);
      j_--;
    } else if (i_ < static_cast<int>(unsorted_list_.size())-1) {
      // Increment i for loop and reset j variable.
      i_++;
      j_ = i_ - 1;
    }
  }
}

void InsertionSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  access_ = 0;
  i_ = 1;
  j_ = i_ - 1;
}
}  // namespace sorting