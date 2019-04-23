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
    Vertex(double x, double y, double z)
    {
      position_x = x;
      position_y = y;
      position_z = z;
    }
  };
  struct Quad
  {
    // This can be calculated on the fly, but it will be used a lot, so pre-calculating it may be better
    double normalAngle_rad;
    double variance;
    double certainty;
    Quad(double n, double v, double c)
    {
      normalAngle_rad = n;
      variance = v;
      certainty = c;
    }
  };

public:
  HalfEdge(shared_ptr<Vertex> base, shared_ptr<Quad> parent, shared_ptr<HalfEdge> prev, shared_ptr<HalfEdge> twin, shared_ptr<HalfEdge> next);
  ~HalfEdge();

  // Accessor Methods
  HalfEdge & next();
  HalfEdge & previous();
  HalfEdge & twin();

  // Mutoator Methods
  void setNext(shared_ptr<HalfEdge> next);
  void setPrevious(shared_ptr<HalfEdge> prev);
  void setTwin(shared_ptr<HalfEdge> twin);

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
