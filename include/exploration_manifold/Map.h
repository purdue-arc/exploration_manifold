#include "exploration_manifold/MapIterator.h"

class Map {
  struct mapHalfEdge
  {
    mapVertex * baseVertex;
    mapQuad * parentQuad;

    mapHalfEdge * prevEdge;
    mapHalfEdge * twinEdge;
    mapHalfEdge * nextEdge;
  };
  struct mapVertex
  {
    double position_x;
    double position_y;
    double position_z;
  };
  struct mapQuad
  {
    double normal_x;
    double normal_y;
    double normal_z;

    double variance;
    double certainty;
  };
public:
    typedef MapIterator iterator;
    Map();
    ~Map();

    iterator begin();
    //iterator end();

    std::pair<std::array<double[3]>, std::array<size_t[4]>> GeneratePatch();

    // Add data, must be linked to existing stuff I guess.
    bool extendMap();

private:
  // Current half edges
  // fronteirs?
  // zeroEdge?
  Map.mapHalfEdge * originEdge;
  unsigned int numQuads;

};
