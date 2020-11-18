#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

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

 private:
  const double kWindowX = 1275;
  const double kWindowY = 875;
  const double kMargin = 100;
};

}  // namespace visualizer

}  // namespace sorting
