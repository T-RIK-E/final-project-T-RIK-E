#include <core/counting_sort.h>

namespace sorting {
CountingSort::CountingSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  max_ = unsorted_list_[0];
  output_.resize(unsorted_list_.size());
  count_.resize(100);
  i_ = 0;
  j_ = 0;
  k_ = 1;
  l_ = unsorted_list_.size()-1;
  m_ = 0;
}

void CountingSort::SortOneStep() {
// The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.

  // Find the largest element of the array
  if(i_ < (int) unsorted_list_.size()) {
    if (unsorted_list_[i_] > max_) {
      max_ = unsorted_list_[i_];
    }
    i_++;
  } else if (j_ < static_cast<int>(unsorted_list_.size())) {
    count_[unsorted_list_[j_]]++;
    j_++;
  } else if (k_ <= static_cast<int>(max_)) {
    count_[k_] += count_[k_ - 1];
    k_++;
  } else if (l_ >= 0) {
    output_[count_[unsorted_list_[l_]] - 1] = unsorted_list_[l_];
    count_[unsorted_list_[l_]]--;
    l_--;
  } else if (m_ < static_cast<int>(unsorted_list_.size())) {
    unsorted_list_[m_] = output_[m_];
    m_++;
  }
}
}  // namespace sorting