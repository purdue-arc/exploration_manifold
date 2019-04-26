#include "exploration_manifold/HalfEdge.h"
#include <memory>
#include <vector>
#include <array>

class Map {
public:
    Map(double v_x [3], double v_y [3]);
    ~Map();

    std::vector<std::array<std::array<double, 3>, 4>> exportGeometry();

    // Add data, must be linked to existing stuff I guess.
    // bool extendMap();

private:
  // Current half edges
  // fronteirs?
  std::shared_ptr<HalfEdge> originEdge;
  std::shared_ptr<HalfEdge> activeEdge;
  unsigned int numQuads;
};
