#include <core/heap_sort.h>

namespace sorting {
HeapSort::HeapSort() : Sort() {
  name_ = "Heap Sort";
  i_ = unsorted_list_.size() / 2 - 1;
  stack_.push(i_--);
  stack_.push(unsorted_list_.size());;
  j_ = unsorted_list_.size() - 1;
}

HeapSort::HeapSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  name_ = "Heap Sort";
  i_ = unsorted_list_.size() / 2 - 1;
  stack_.push(i_--);
  stack_.push(unsorted_list_.size());;
  j_ = unsorted_list_.size() - 1;
}

void HeapSort::SortOneStep() {
  bool go = Heapify();
  // If stack is empty and we finished creating the heap
  if (stack_.empty() && go) {
    if (i_ >= 0) {
      // Create heap on the root tree
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
    // If stack not empty but still go, read next parameters in stack and keep
    // heaping.
    heap_size_ = stack_.top();
    stack_.pop();
    root_ = stack_.top();
    stack_.pop();

    largest_ = root_;        // Initialize largest as root
    index_ = 2 * root_ + 1;  // left = 2*i + 1
  }
}

void HeapSort::ReInitialize() {
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
  access_ = 0;
  i_ = unsorted_list_.size() / 2 - 1;
  stack_.push(i_--);
  stack_.push(unsorted_list_.size());;
  j_ = unsorted_list_.size() - 1;
}

bool HeapSort::Heapify() {
  // If left child is larger than root
  if (index_ < heap_size_ &&
      unsorted_list_[index_] > unsorted_list_[largest_]) {
    largest_ = index_;
    access_+=2;
    height1_ = unsorted_list_[index_];
    height2_ = unsorted_list_[largest_];
  }
  index_++;

  // If the heapify has finished looping through
  if (index_ > 2 * root_ + 3 || i_ == unsorted_list_.size() / 2 - 2) {
    // If the largest number is not the root
    if (largest_ != root_) {
      // Swap the root and the largest
      swap(unsorted_list_[root_], unsorted_list_[largest_]);

      // Add the parameters to the stack that normally would be recurively
      // solved
      stack_.push(largest_);
      stack_.push(heap_size_);
    }
    // To continue the next sorting process
    return true;
  } else {
    // To continue creating the heap.
    return false;
  }
}
}  // namespace sorting