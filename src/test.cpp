#include "exploration_manifold/Map.h"
#include "exploration_manifold/Plot3D.h"
#include <iostream>

int main(){
  double test_x [3] = {5, 0, 1};
  double test_y [3] = {0, 7, -3};

  Map map = Map(test_x, test_y);

  Plot3D plot;

  // Plot3D::Polygon poly ({-5,-5,-1}, {-5,5,0}, {5,5,1}, {5,-5,0});
  // plot.addPolygon(poly);

  std::vector<std::array<std::array<double, 3>, 4>> geometry = map.exportGeometry();

  for(auto itr = geometry.begin(); itr < geometry.end(); ++itr){
    Plot3D::Polygon poly ((*itr)[0], (*itr)[1], (*itr)[2], (*itr)[3]);
    plot.addPolygon(poly);
  }

  // keep it running so the gnuplot is responsive
  std::cout << "waiting" << std::endl;
  std::cin.get();
  plot.closePlot();
  return 0;
}
