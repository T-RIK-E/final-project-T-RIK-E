#include <core/quick_sort.h>

namespace sorting {
QuickSort::QuickSort() : Sort() {
  name_ = "Quick Sort";
  partitioned_ = false;
  go_ = true;
  low_ = 0;
  high_ = unsorted_list_.size() -1;
  stack_.push(low_);
  stack_.push(high_);
}

QuickSort::QuickSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Quick Sort";
  partitioned_ = false;
  go_ = true;
  low_ = 0;
  high_ = unsorted_list_.size() -1;
  stack_.push(low_);
  stack_.push(high_);
}

void QuickSort::SortOneStep() {
  if (go_ || !stack_.empty()) {
    if (!partitioned_) {
      high_ = stack_.top();
      stack_.pop();
      low_ = stack_.top();
      stack_.pop();

      i_ = (low_ - 1);
      j_ = low_;

      go_ = true;
      partitioned_ = !partitioned_;
    } else if (partition()) {

      if (pivot_ - 1 > low_) {
        stack_.push(low_);
        stack_.push(pivot_ - 1);
      }

      if (pivot_ + 1 < high_) {
        stack_.push(pivot_ + 1);
        stack_.push(high_);
      } else if (pivot_ - 1 <= low_) {
        go_ = false;
      }
      partitioned_ = !partitioned_;
    }
  }
}

void QuickSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  partitioned_ = false;
  go_ = true;
  low_ = 0;
  high_ = unsorted_list_.size() -1;
  stack_.push(low_);
  stack_.push(high_);
}

bool QuickSort::partition() {
  if (j_ <= high_ - 1) {
    height1_ = unsorted_list_[j_];
    height2_ = unsorted_list_[high_];
    if (unsorted_list_[j_] <= unsorted_list_[high_]) {
      access_+=2;
      i_++;
      swap(unsorted_list_[i_], unsorted_list_[j_]);
    }
    j_++;
    return false;
  } else {
    swap(unsorted_list_[i_ + 1], unsorted_list_[high_]);
    pivot_ = (i_ + 1);
    return true;
  }
}
}  // namespace sorting