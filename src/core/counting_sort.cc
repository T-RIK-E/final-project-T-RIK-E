#include <core/counting_sort.h>

namespace sorting {
CountingSort::CountingSort() : Sort() {
  name_ = "Counting Sort";
  max_ = unsorted_list_[0];
  access_ = 1;
  output_.resize(unsorted_list_.size());
  count_.resize(100);
  i_ = 0;
  j_ = 0;
  k_ = 1;
  l_ = unsorted_list_.size()-1;
  m_ = 0;
}
CountingSort::CountingSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Counting Sort";
  max_ = unsorted_list_[0];
  access_ = 1;
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
  if(i_ < static_cast<int>(unsorted_list_.size())) {
    height1_ = unsorted_list_[i_];
    height2_ = max_;
    if (unsorted_list_[i_] > max_) {
      max_ = unsorted_list_[i_];
    }
    access_++;
    i_++;
  } else if (j_ < static_cast<int>(unsorted_list_.size())) {
    height2_ = -1;
    height1_ = unsorted_list_[j_];
    count_[unsorted_list_[j_]]++;
    access_++;
    j_++;
  } else if (k_ <= static_cast<int>(max_)) {
    count_[k_] += count_[k_ - 1];
    k_++;
  } else if (l_ >= 0) {
    height1_ = unsorted_list_[l_];
    output_[count_[unsorted_list_[l_]] - 1] = unsorted_list_[l_];
    access_+=2;
    count_[unsorted_list_[l_]]--;
    access_++;
    l_--;
  } else if (m_ < static_cast<int>(unsorted_list_.size())) {
    height1_ = unsorted_list_[m_];
    height2_ = output_[m_];
    unsorted_list_[m_] = output_[m_];
    access_++;
    m_++;
  }
}

void CountingSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  access_ = 0;
  max_ = unsorted_list_[0];
  access_ = 1;
  output_.resize(unsorted_list_.size());
  count_.resize(100);
  i_ = 0;
  j_ = 0;
  k_ = 1;
  l_ = unsorted_list_.size()-1;
  m_ = 0;
}
}  // namespace sorting