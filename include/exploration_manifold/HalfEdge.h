#include <array>
#include <shared_ptr>

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
  HalfEdge(shared_ptr<Vertex> base, shared_ptr<Quad> parent, shared_ptr<HalfEdge> prev, shared_ptr<HalfEdge> twin, shared_ptr<HalfEdge> next);
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
  HalfEdgeIterator iterator();

private:
  shared_ptr<Vertex> baseVertex;
  shared_ptr<Quad> parentQuad;

  shared_ptr<HalfEdge> prevEdge;
  shared_ptr<HalfEdge> twinEdge;
  shared_ptr<HalfEdge> nextEdge;
};
