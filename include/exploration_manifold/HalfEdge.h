#include "exploration_manifold/HalfEdgeIterator.h"
#include <array>
#include <memory>

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
  HalfEdge(std::shared_ptr<Vertex> base, std::shared_ptr<Quad> parent, std::shared_ptr<HalfEdge> prev, std::shared_ptr<HalfEdge> twin, std::shared_ptr<HalfEdge> next);
  ~HalfEdge();

  // Accessor Methods
  std::shared_ptr<HalfEdge> next();
  std::shared_ptr<HalfEdge> previous();
  std::shared_ptr<HalfEdge> twin();
  std::shared_ptr<Quad> parent();


  // Mutoator Methods
  void setNext(std::shared_ptr<HalfEdge> next);
  void setPrevious(std::shared_ptr<HalfEdge> prev);
  void setTwin(std::shared_ptr<HalfEdge> twin);

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

private:
  std::shared_ptr<Vertex> baseVertex;
  std::shared_ptr<Quad> parentQuad;

  std::shared_ptr<HalfEdge> prevEdge;
  std::shared_ptr<HalfEdge> twinEdge;
  std::shared_ptr<HalfEdge> nextEdge;
};
