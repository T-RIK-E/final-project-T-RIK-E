//
// Created by rtera on 11/17/2020.
//

#pragma once
#include <vector>

namespace sorting {
class Sort {
 public:
  explicit Sort(std::vector<size_t> unsorted_list);
  virtual ~Sort();
  virtual void SortOneStep() = 0;

  const std::vector<size_t>& GetUnsortedList() const;
  const size_t GetHeight1() const;
  const size_t GetHeight2() const;
  const std::string GetName() const;
 protected:
  void swap(size_t& a, size_t& b);
  std::vector<size_t> GenerateList();

  std::vector<size_t> unsorted_list_;
  size_t height1_;
  size_t height2_;
  std::string name_;
};
}
