#include <cinder/gl/gl.h>
#include <visualizer/ideal_gas_app.h>

using glm::vec2;
namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
    : container_(glm::vec2(kMargin, kMargin), kContainerSize, kContainerSize) {
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);

  //Create initial particles for demo
  CreateInitialParticles();
  //Initialize the graph for demo
  InitializeGraphs();
}

void IdealGasApp::draw() {
  // Create background
  ci::Color8u background_color(255, 246, 148);  // light yellow
  ci::gl::clear(background_color);

  // Draw the container
  container_.DrawContainer();
  // Draw all the particles
  simulation_.DrawParticles();

  for (Histogram& hist: histograms) {
    //For each histogram, draw
    hist.DrawHistogram();
  }
}

void IdealGasApp::update() {
  //Get lower and upper bounds of app
  glm::vec2 lower = container_.GetTopLeftCorner();
  glm::vec2 upper = container_.GetTopLeftCorner() +
                    glm::vec2(container_.GetPixelsX(), container_.GetPixelsY());
  // Run the simulation
  simulation_.RunSimulation(lower, upper);

  for (Histogram& hist: histograms) {
    //First empty the bin
    hist.EmptyBins();
    for (const Particle& p : simulation_.GetParticles()) {
      //Re-add each particles to their respective bin
      //Check to put in right histogram
      if (p.GetMass() == hist.GetMassType()) {
        hist.AddToBin(p);
      }
    }
  }
}


/**
 * These two private methods are for this week's demo
 */
void IdealGasApp::CreateInitialParticles() {
  //Get lower and upper bound of container
  glm::vec2 lower = container_.GetTopLeftCorner();
  glm::vec2 upper = container_.GetTopLeftCorner() +
                    glm::vec2(container_.GetPixelsX(), container_.GetPixelsY());

  //Generates initial particle amount
  simulation_.GenerateParticles(
      50, 3, 10.0f, ci::Color(1, 0, 0), lower, upper);
  simulation_.GenerateParticles(
      50, 5, 20.0f, ci::Color(0, 1, 0), lower, upper);
  simulation_.GenerateParticles(
      50, 8, 30.0f, ci::Color(0, 0, 1), lower, upper);
}

void IdealGasApp::InitializeGraphs() {
  //Initialize the first histogram
  glm::vec2 top_left(2 * kMargin + kContainerSize, kMargin);
  Particle::ParticleModel model1(3, 10, ci::Color(1, 0, 0));
  Histogram histogram1(top_left, kHistX, kHistY, &model1);

  //Set the bin number and add to the histogram
  histogram1.SetBins(25);
  histograms.push_back(histogram1);

  //Same procedure, change the location of histogram to avoid overlap
  top_left += glm::vec2(0, kHistY+kMargin);
  Particle::ParticleModel model2(5, 20, ci::Color(0, 1 , 0));
  Histogram histogram2(top_left, kHistX, kHistY, &model2);
  histogram2.SetBins(25);
  histograms.push_back(histogram2);

  top_left += glm::vec2(0, kHistY+kMargin);
  Particle::ParticleModel model3(8, 30, ci::Color(0, 0, 1));
  Histogram histogram3(top_left, kHistX, kHistY, &model3);
  histogram3.SetBins(25);
  histograms.push_back(histogram3);
}

}  // namespace visualizer
}  // namespace idealgas
