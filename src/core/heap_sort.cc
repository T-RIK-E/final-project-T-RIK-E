#include <core/heap_sort.h>

namespace sorting {
HeapSort::HeapSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  i_ = unsorted_list_.size() / 2 - 1;
  stack_.push(i_--);
  stack_.push(unsorted_list_.size());;
  j_ = unsorted_list_.size() - 1;
}

void HeapSort::SortOneStep() {
  bool go = Heapify();
  if (stack_.empty() && go) {
    // Build heap (rearrange array)
    if (i_ >= 0) {
      stack_.push(i_--);
      stack_.push(unsorted_list_.size());;
    } else if (j_ > 0) {
      // Move current root to end
      swap(unsorted_list_[0], unsorted_list_[j_]);

      // call max heapify on the reduced heap
      stack_.push(0);
      stack_.push(j_--);
    }
  } else if (go) {
    heap_size_ = stack_.top();
    stack_.pop();
    root_ = stack_.top();
    stack_.pop();

    largest_ = root_;        // Initialize largest as root
    index_ = 2 * root_ + 1;  // left = 2*i + 1
  }
}

bool HeapSort::Heapify() {
  // If left child is larger than root
  if (index_ < heap_size_ &&
      unsorted_list_[index_] > unsorted_list_[largest_]) {
    largest_ = index_;
  }
  index_++;

  // If largest is not root
  if (index_ > 2 * root_ + 3 || i_ == unsorted_list_.size() / 2 - 2) {
    if (largest_ != root_) {
      swap(unsorted_list_[root_], unsorted_list_[largest_]);

      // Recursively heapify the affected sub-tree
      stack_.push(largest_);
      stack_.push(heap_size_);
    }
    return true;
  } else {
    return false;
  }
}
}  // namespace sorting