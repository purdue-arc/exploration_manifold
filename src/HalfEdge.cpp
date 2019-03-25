include "exploration_manifold/HalfEdge.h"

namespace purdue_arc
{

  HalfEdge::HalfEdge()
  {
      double[] baseVertex;
      std::shared_ptr<Quad> parentQuad;

      // Linked half-edges
      std::shared_ptr<HalfEdge> prevEdge;
      std::shared_ptr<HalfEdge> twinEdge;
      std::shared_ptr<HalfEdge> nextEdge;
  }

  HalfEdge::~HalfEdge()
  {

  }

}
