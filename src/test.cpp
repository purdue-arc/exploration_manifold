#include "exploration_manifold/Map.h"
#include "exploration_manifold/Plot3D.h"

int main(){
  double test_x [3] = {1, 0, 0};
  double test_y [3] = {0, 1, 0};

  Map map = Map(test_x, test_y);

  Plot3D plot;

  Plot3D::Polygon poly ({0,0,0}, {1,0,0}, {0,1,0}, {1,1,1});
  plot.addPolygon(poly);

  return 0;
}
