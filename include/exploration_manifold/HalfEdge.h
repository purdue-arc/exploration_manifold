#include <array>

// Forward declare iterator
class HalfEdgeIterator;

class HalfEdge{
  struct Vertex
  {
    double position_x;
    double position_y;
    double position_z;
  };
  struct Quad
  {
    // This can be calculated on the fly, but it will be used a lot, so pre-calculating it may be better
    double normalAngle_rad;
    double variance;
    double certainty;
  };

public:
  HalfEdge(Vertex base, Quad parent, HalfEdge prev, HalfEdge twin, HalfEdge next);
  ~HalfEdge();

  // Accessor Methods
  HalfEdge & next();
  HalfEdge & previous();
  HalfEdge & twin();

  // Parent Accessor Methods
  double parentNormalAngle();
  double parentVariance();
  double parentCertainty();

  // Other
  bool hasTwin();
  std::array<double, 3> parentNormal();
  std::array<double, 3> vector();
  HalfEdgeIterator parentIterator();

private:
  Vertex * baseVertex;
  Quad * parentQuad;

  HalfEdge * prevEdge;
  HalfEdge * twinEdge;
  HalfEdge * nextEdge;
};
