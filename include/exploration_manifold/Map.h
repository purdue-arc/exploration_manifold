#include "exploration_manifold/HalfEdgeMap.h"
#include "exploration_manifold/MapIterator.h"
#include <shared_ptr>

class Map {
public:
    Map(double v_x [3], double v_y [3]);
    ~Map();

    // std::pair<std::array<double[3]>, std::array<size_t[4]>> GeneratePatch();

    // Add data, must be linked to existing stuff I guess.
    // bool extendMap();

private:
  // Current half edges
  // fronteirs?
  // zeroEdge?
  std::shared_ptr<HalfEdge> originEdge;
  std::shared_ptr<HalfEdge> activeEdge;
  unsigned int numQuads;
};
