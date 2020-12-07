#include <visualizer/algorithms.h>
#include <visualizer/container.h>
#include <random>
#include <algorithm>

namespace sorting {
Container::Container(const glm::vec2 &top_left, size_t pixels_x,
                     size_t pixels_y)
    : top_left_(top_left), pixels_x_(pixels_x), pixels_y_(pixels_y) {
  InitializeList();
  it = sort_list_.begin();
}

void Container::DrawFrame() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_, top_left_ + glm::vec2(pixels_x_, pixels_y_)));

  DrawList();
  PrintName();
}

void Container::Update() {
  (*it)->SortOneStep();
}

void Container::CleanUp() {
  for (it = sort_list_.begin(); it != sort_list_.end(); it++) {
    delete it._Ptr->_Myval;
  }
}

void Container::DrawList() const {
  size_t width = 0;
  for (size_t height : (*it)->GetUnsortedList()) {
    glm::vec2 top_left =
        top_left_ + glm::vec2(width, 0) + glm::vec2(0, pixels_y_ - height);

    if ((*it)->GetHeight1() == height ||
    (*it)->GetHeight2() == height) {
      ci::gl::color(ci::Color("red"));
    } else {
      ci::gl::color(ci::Color("black"));
    }
    ci::gl::drawSolidRect(
        ci::Rectf(top_left, top_left + glm::vec2(kWidth, height)));

    width += 10;
  }
}

void Container::Decrement() {
  it--;
}

void Container::Increment() {
  it++;
}

void Container::PrintName() const {
  ci::gl::drawString((*it)->GetName(), glm::vec2(15, 20),
                     ci::Color(0, 0, 0), ci::Font("Title Font", 30));
}

void Container::InitializeList() {
  std::vector<size_t> list;
  list.reserve(100);
  for (size_t i = 0; i < 100; i++) {
    list.push_back(i);
  }
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(list), std::end(list), rng);

  sort_list_.push_back(new BubbleSort(list));
  sort_list_.push_back(new CombSort(list));
  sort_list_.push_back(new CountingSort(list));
  sort_list_.push_back(new HeapSort(list));
  sort_list_.push_back(new InsertionSort(list));
  sort_list_.push_back(new MergeSort(list));
  sort_list_.push_back(new QuickSort(list));
  sort_list_.push_back(new SelectionSort(list));
  sort_list_.push_back(new ShellSort(list));
}
}  // namespace sorting