#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"
#include "histogram.h"
#include "core/simulation.h"

namespace idealgas {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class IdealGasApp: public ci::app::App {
 public:
  IdealGasApp();

  void draw() override;
  void update() override;

 private:
  const double kWindowX = 1275;
  const double kWindowY = 875;
  const double kMargin = 100;
  const size_t kContainerSize = 675;
  const float kHistX = 300;
  const float kHistY = 150;

  Simulation simulation_;
  Container container_;
  std::vector<Histogram> histograms;

  /**
   * This creates all the initial particles that need to be generated for this
   * week's code
   */
  void CreateInitialParticles();

  /**
   * This initialized the 3 histogram that are needed for this week's code
   */
  void InitializeGraphs();
};

}  // namespace visualizer

}  // namespace naivebayes
