#include "exploration_manifold/HalfEdgeIterator.h"
#include <array>

class HalfEdge{
public:
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

  typedef HalfEdgeIterator iterator;
  HalfEdge(Vertex* base, Quad* parent, HalfEdge* prev, HalfEdge* twin, HalfEdge* next);
  ~HalfEdge();

  // Accessor Methods
  HalfEdge* next();
  HalfEdge* previous();
  HalfEdge* twin();
  Quad* parent();


  // Mutator Methods
  void setNext(HalfEdge* next);
  void setPrevious(HalfEdge* prev);
  void setTwin(HalfEdge* twin);

  // Parent Accessor Methods
  double parentNormalAngle();
  double parentVariance();
  double parentCertainty();
  std::array<double, 3> parentNormal();

  // Child Accessor Methods
  std::array<double, 3> vertexLocation();
  std::array<double, 3> vector();

  // Other
  bool hasTwin();
  iterator begin();
  iterator end();

private:
  Vertex* baseVertex;
  Quad* parentQuad;

  HalfEdge* prevEdge;
  HalfEdge* twinEdge;
  HalfEdge* nextEdge;
};
