#include "exploration_manifold/HalfEdgeMap.h"
#include "exploration_manifold/MapIterator.h"

class Map {
public:
    typedef MapIterator iterator;
    Map();
    ~Map();

    iterator begin();
    iterator end();

    std::pair<std::array<double[3]>, std::array<size_t[4]>> GeneratePatch();

    // Add data, must be linked to existing stuff I guess.
    bool extendMap();

private:
  // Current half edges
  // fronteirs?
  // zeroEdge?
  mapHalfEdge * firstEdge;
  mapHalfEdge * lastEdge;
  
  unsigned int numQuads;

};
