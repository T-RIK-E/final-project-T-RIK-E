//
// Created by rtera on 11/17/2020.
//

#pragma once
#include <vector>

namespace sorting {
class Sort {
 public:
  Sort(std::vector<size_t> unsorted_list);
  virtual void SortOneStep() = 0;
  const std::vector<size_t>& GetUnsortedList() const;
 protected:
  std::vector<size_t> unsorted_list_;
};
}
