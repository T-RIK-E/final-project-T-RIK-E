#include <core/counting_sort.h>

namespace sorting {
CountingSort::CountingSort() : Sort() {
  name_ = "Counting Sort";
  access_ = 0;
  max_ = 99;
  output_.resize(unsorted_list_.size());
  count_.resize(100);
  j_ = 0;
  k_ = 1;
  l_ = unsorted_list_.size()-1;
  m_ = 0;
}
CountingSort::CountingSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Counting Sort";
  access_ = 0;
  // We know the range of the list
  max_ = 99;
  // Size the two lists to loops through them
  output_.resize(unsorted_list_.size());
  count_.resize(100);

  // Set the initial conditions of the loop.
  j_ = 0;
  k_ = 1;
  l_ = unsorted_list_.size()-1;
  m_ = 0;
}

void CountingSort::SortOneStep() {
  // Loop through unsorted array log the number of times a number appears in
  // the unsorted array.
  if (j_ < static_cast<int>(unsorted_list_.size())) {
    height2_ = -1;
    height1_ = unsorted_list_[j_];
    count_[unsorted_list_[j_]]++;
    access_++;
    j_++;
  // Add all the previous numbers to the next number in count
  } else if (k_ <= static_cast<int>(max_)) {
    count_[k_] += count_[k_ - 1];
    k_++;
  // Do math to get an output of sorted arrays
  } else if (l_ >= 0) {
    height1_ = unsorted_list_[l_];
    output_[count_[unsorted_list_[l_]] - 1] = unsorted_list_[l_];
    access_+=2;
    count_[unsorted_list_[l_]]--;
    access_++;
    l_--;
  // Copy the output array into the unsorted array to get a sorted array.
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
  max_ = 99;
  output_.resize(unsorted_list_.size());
  count_.resize(100);
  j_ = 0;
  k_ = 1;
  l_ = unsorted_list_.size()-1;
  m_ = 0;
}
}  // namespace sorting