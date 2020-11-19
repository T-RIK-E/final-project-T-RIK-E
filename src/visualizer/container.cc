#include <visualizer/container.h>
#include <core/insertion_sort.h>

namespace sorting {
Container::Container(const glm::vec2 &top_left, size_t pixels_x,
                     size_t pixels_y)
    : top_left_(top_left), pixels_x_(pixels_x), pixels_y_(pixels_y) {
  std::vector<size_t> list;
  list.reserve(100);
for (size_t i = 0; i<100; i++) {
    list.push_back(i);
  }

  InsertionSort insertionSort(list);
  sorting_algo_ = &insertionSort;
}

void Container::DrawFrame() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_, top_left_ + glm::vec2(pixels_x_, pixels_y_)));


  for (size_t height : sorting_algo_->GetUnsortedList()) {
    glm::vec2 top_left = top_left_ + glm::vec2(0, pixels_y_ - height);

    ci::gl::drawSolidRect(
        ci::Rectf(top_left, top_left + glm::vec2(kWidth, height)));
  }
}
}  // namespace sorting