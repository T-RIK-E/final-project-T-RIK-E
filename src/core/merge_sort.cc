#include <core/merge_sort.h>

#include <algorithm>

namespace sorting {
MergeSort::MergeSort() : Sort() {
  name_ = "Merge Sort";
  SplitArray();
  sorted_ = true;
}

MergeSort::MergeSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Merge Sort";
  SplitArray();
  sorted_ = true;
}

void MergeSort::SortOneStep() {
  // If queue contains sub arrays and previous sub array is sorted
  if (!indexes_.empty() && sorted_) {
    // Get new array indices
    size_t low = indexes_.front();
    indexes_.pop();
    size_t mid = indexes_.front();
    indexes_.pop();
    size_t high = indexes_.front();
    indexes_.pop();

    // Resize the left and right sub arrays and copy from unsorted_list_
    left_.resize(mid - low + 1);
    right_.resize(high - mid);

    for (size_t i = 0; i < left_.size(); i++) {
      left_[i] = unsorted_list_[low + i];
      access_++;
    }
    for (size_t i = 0; i < right_.size(); i++) {
      right_[i] = unsorted_list_[mid + 1 + i];
      access_++;
    }
    i_ = 0;
    j_ = 0;
    k_ = low;
    sorted_ = false;
  } else if (!sorted_) {
    // If not sorted, sort the subarray
    Merge();
  }
}

void MergeSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  access_ = 0;
  SplitArray();
  sorted_ = true;
}

void MergeSort::Merge() {
  // If the i and j are at the end, then arrays have been merged
  if (i_ == left_.size() && j_ == right_.size()) {
    sorted_ = true;
  // If right elements only remain, add to larger array
  } else if (i_ == left_.size()) {
    height2_ = right_[j_];
    unsorted_list_[k_++] = right_[j_++];
  // If left elements only remain, add to larger array
  } else if (j_ == right_.size()) {
    height1_ = left_[i_];
    unsorted_list_[k_++] = left_[i_++];
  // If right element is larger than left, then left element first
  } else if (left_[i_] < right_[j_]) {
    height1_ = left_[i_];
    height2_ = right_[j_];
    unsorted_list_[k_++] = left_[i_++];
  // Else add right element.
  } else {
    unsorted_list_[k_++] = right_[j_++];
  }
  access_++;
}

void MergeSort::SplitArray() {
  // Merge subarrays in bottom up manner.  First merge subarrays of
  // size 1 to create sorted subarrays of size 2, then merge subarrays
  // of size 2 to create sorted subarrays of size 4, and so on.
  for (size_t curr_size = 1; curr_size <= unsorted_list_.size() - 1;
       curr_size = 2 * curr_size) {
    // Pick starting point of different subarrays of current size
    for (size_t left_start = 0; left_start < unsorted_list_.size() - 1;
         left_start += 2 * curr_size) {
      // Find ending point of left subarray. mid+1 is starting
      // point of right
      int mid = std::min(left_start + curr_size - 1, unsorted_list_.size() - 1);

      int right_end =
          std::min(left_start + 2 * curr_size - 1, unsorted_list_.size() - 1);

      indexes_.push(left_start);
      indexes_.push(mid);
      indexes_.push(right_end);
    }
  }
}
}  // namespace sorting