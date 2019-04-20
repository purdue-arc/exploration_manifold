#include "exploration_manifold/HalfEdge.h"

class HalfEdgeIterator {
public:
  HalfEdgeIterator(HalfEdge & edge);
  ~HalfEdgeIterator();

  // Standard operations
  HalfEdgeIterator & operator++();
  HalfEdgeIterator operator++(int);
  HalfEdgeIterator & operator--();
  HalfEdgeIterator operator--(int);
  HalfEdge & operator*();

private:
  HalfEdge & edge;
};
