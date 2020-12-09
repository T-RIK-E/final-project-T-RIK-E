#include <core/shell_sort.h>

namespace sorting {
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
      if (j_ >= 0 && unsorted_list_[j_] > unsorted_list_[j_ + gap_]) {
        access_+=2;
        swap(unsorted_list_[j_ + gap_], unsorted_list_[j_]);
        height1_ = unsorted_list_[j_ + gap_];
        height2_ = unsorted_list_[j_];
        j_ -= gap_;
      } else if (i_ < static_cast<int>(unsorted_list_.size()) - gap_ + 1) {
        i_ += gap_;
        j_ = i_ - gap_;
      }
    } else {
      gap_ /= 2;
      i_ = gap_;
    }
  }
}

int ShellSort::UpperBound(size_t num) {
  while (num + gap_ <= unsorted_list_.size()) {
    num += gap_;
  }
  return num;
}
} // namespace sorting