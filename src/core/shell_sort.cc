#include <core/shell_sort.h>

namespace sorting {
ShellSort::ShellSort() : Sort() {
  name_ = "Shell Sort";
  gap_ = unsorted_list_.size()/2;
  i_ = gap_;
  j_ = i_ - gap_;
}

ShellSort::ShellSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Shell Sort";
  gap_ = unsorted_list_.size()/2;
  i_ = gap_;
  j_ = i_ - gap_;
}

void ShellSort::SortOneStep() {
  if (gap_ > 0) {
    if (i_ < UpperBound(gap_)) {
      // While i is less than the upper bound
      if (j_ >= 0 && unsorted_list_[j_] > unsorted_list_[j_ + gap_]) {
        // Swap if j is larger than the next gapped index
        access_+=2;
        swap(unsorted_list_[j_ + gap_], unsorted_list_[j_]);
        height1_ = unsorted_list_[j_ + gap_];
        height2_ = unsorted_list_[j_];
        j_ -= gap_;
      } else if (i_ < static_cast<int>(unsorted_list_.size()) - gap_ + 1) {
        // Else increment by gap
        i_ += gap_;
        j_ = i_ - gap_;
      }
    } else {
      gap_ /= 2;
      i_ = gap_;
    }
  }
}

void ShellSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  access_ = 0;
  gap_ = unsorted_list_.size()/2;
  i_ = gap_;
  j_ = i_ - gap_;
}

int ShellSort::UpperBound(size_t num) {
  // Add gap to num while total is smaller than size of array.
  while (num + gap_ <= unsorted_list_.size()) {
    num += gap_;
  }
  return num;
}
} // namespace sorting