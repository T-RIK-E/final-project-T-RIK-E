#include <cinder/gl/gl.h>
#include <visualizer/sorting_visualizer_app.h>

using glm::vec2;
namespace sorting {

namespace visualizer {

SortingApp::SortingApp()
    : container(glm::vec2(0, 0), kContainerX, kContainerY) {
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);
}

void SortingApp::draw() {
  container.DrawFrame();
}

void SortingApp::update() {
  container.Update();
}

void SortingApp::cleanup() {
  container.CleanUp();
}

void SortingApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_LEFT:
      container.Decrement();
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      container.Increment();
      break;
  }
}
}  // namespace visualizer
}  // namespace sorting
