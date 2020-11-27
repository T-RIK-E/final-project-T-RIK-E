#include <core/quick_sort.h>
#include <visualizer/container.h>

#include <algorithm>
#include <random>

namespace sorting {
Container::Container(const glm::vec2 &top_left, size_t pixels_x,
                     size_t pixels_y)
    : top_left_(top_left), pixels_x_(pixels_x), pixels_y_(pixels_y) {
  std::vector<size_t> list;
  list.reserve(100);
  for (size_t i = 0; i < 100; i++) {
    list.push_back(i);
  }

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(list), std::end(list), rng);

  sorting_algo_ = new QuickSort(list);
}

void Container::DrawFrame() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_, top_left_ + glm::vec2(pixels_x_, pixels_y_)));

  size_t width = 0;
  for (size_t height : sorting_algo_->GetUnsortedList()) {
    glm::vec2 top_left =
        top_left_ + glm::vec2(width, 0) + glm::vec2(0, pixels_y_ - height);

    if (sorting_algo_->GetHeight1() == height ||
        sorting_algo_->GetHeight2() == height){
      ci::gl::color(ci::Color("red"));
    } else {
      ci::gl::color(ci::Color("black"));
    }
    ci::gl::drawSolidRect(
        ci::Rectf(top_left, top_left + glm::vec2(kWidth, height)));

    width += 10;
  }
}

void Container::Update() {
  sorting_algo_->SortOneStep();
}

void Container::CleanUp() {
  delete sorting_algo_;
}
}  // namespace sorting