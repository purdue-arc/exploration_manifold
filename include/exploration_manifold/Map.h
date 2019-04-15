class Map {
  struct mapGeometry
  {
    size_t key;

    bool operator<(meshGeometry other) const
    {
      return other.key < this.key;
    }
  };

  struct mapHalfEdge : mapGeometry
  {
    mapVertex * baseVertex;
    mapQuad * parentQuad;

    mapHalfEdge * prevEdge;
    mapHalfEdge * twinEdge;
    mapHalfEdge * nextEdge;
  };

  struct mapVertex : mapGeometry
  {
    double position_x;
    double position_y;
    double position_z;
  };

  struct mapQuad : mapGeometry
  {
    double normal_x;
    double normal_y;
    double normal_z;

    double variance;
    double certainty;
  };
public:
    Map();
    ~Map();

    std::pair<std::array<double[3]>, std::array<size_t[4]>> Map::GeneratePatch();

    // Add data, must be linked to existing stuff I guess.
    bool extendMap();

private:
  // Current half edges
  // fronteirs?
  // zeroEdge?



  mapHalfEdge * originEdgePt;
  unsigned int numQuads;

};
