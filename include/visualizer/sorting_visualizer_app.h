#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <visualizer/container.h>

namespace sorting {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class SortingApp : public ci::app::App {
 public:
  SortingApp();

  void draw() override;
  void update() override;
  void cleanup() override;
  void keyDown(ci::app::KeyEvent event) override;

 private:
  const size_t kWindowX = 1000;
  const size_t kWindowY = 875;
  const size_t kContainerX = 1000;
  const size_t kContainerY = 875;
  const size_t kMargin = 100;

  Container container;
};

}  // namespace visualizer

}  // namespace sorting
