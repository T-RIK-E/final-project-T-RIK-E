#include <cinder/gl/gl.h>
#include <visualizer/sorting_visualizer_app.h>
#include <algorithm>
#include <random>

using glm::vec2;
namespace sorting {

namespace visualizer {

SortingApp::SortingApp() : top_left_(glm::vec2(0, 0)) {
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);

  InitializeList();
  it_ = sort_list_.begin();
  stopped_ = false;
}

void SortingApp::draw() {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_, top_left_ + glm::vec2(kWindowX, kWindowY)));
  DrawList();
  PrintName();
}

void SortingApp::update() {
  if (!stopped_) {
    (*it_)->SortOneStep();
  }
}

void SortingApp::cleanup() {
  for (it_ = sort_list_.begin(); it_ != sort_list_.end(); it_++) {
    delete it_._Ptr->_Myval;
  }
}

void SortingApp::DrawList() const {
  size_t width = 0;
  for (size_t height : (*it_)->GetUnsortedList()) {
    glm::vec2 top_left =
        top_left_ + glm::vec2(width, 0) + glm::vec2(0, kWindowY - height);

    if ((*it_)->GetHeight1() == height ||
        (*it_)->GetHeight2() == height) {
      ci::gl::color(ci::Color("red"));
    } else {
      ci::gl::color(ci::Color("black"));
    }
    ci::gl::drawSolidRect(
        ci::Rectf(top_left, top_left + glm::vec2(kWidth, height)));

    width += 10;
  }
}

void SortingApp::PrintName() const {
  ci::gl::drawString((*it_)->GetName(), glm::vec2(15, 20),
                     ci::Color(0, 0, 0), ci::Font("Title Font", 30));

  ci::gl::drawString(kAccess + std::to_string((*it_)->GetAccess()), glm::vec2(15, 70),
                     ci::Color(0, 0, 0), ci::Font("Title Font", 30));
}

void SortingApp::InitializeList() {
  sort_list_.push_back(new BubbleSort());
  sort_list_.push_back(new CombSort());
  sort_list_.push_back(new CountingSort());
  sort_list_.push_back(new HeapSort());
  sort_list_.push_back(new InsertionSort());
  sort_list_.push_back(new MergeSort());
  sort_list_.push_back(new QuickSort());
  sort_list_.push_back(new SelectionSort());
  sort_list_.push_back(new ShellSort());
}

void SortingApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_LEFT:
      if (it_ != sort_list_.begin()) {
        it_--;
      }
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      if (it_ != --sort_list_.end()) {
        it_++;
      }
      break;
    case ci::app::KeyEvent::KEY_SPACE:
      stopped_ = !stopped_;
      break;
    case ci::app::KeyEvent::KEY_r:
      it_._Ptr->_Myval;
      break;
  }
}
}  // namespace visualizer
}  // namespace sorting
