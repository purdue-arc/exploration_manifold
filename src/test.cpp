#include "exploration_manifold/Map.h"
#include "exploration_manifold/Plot3D.h"
#include <iostream>

int main(){
  double test_x [3] = {1, 0, 0};
  double test_y [3] = {0, 1, 0};

  Map map = Map(test_x, test_y);

  Plot3D plot;

  Plot3D::Polygon poly ({-5,-5,-1}, {-5,5,0}, {5,5,1}, {5,-5,0});
  plot.addPolygon(poly);

  // keep it running so the gnuplot is responsive
  return 0;
}
