#include <memory>
// forward declare the HalfEdge class
class HalfEdge;

class HalfEdgeIterator {
public:
  HalfEdgeIterator(HalfEdge * edge);
  ~HalfEdgeIterator();

  // Standard operations
  HalfEdgeIterator & operator++();
  HalfEdgeIterator operator++(int);
  HalfEdgeIterator & operator--();
  HalfEdgeIterator operator--(int);
  HalfEdge & operator*();
  HalfEdge * operator->();
  bool operator!=(const HalfEdgeIterator & other);

private:
  HalfEdge * edge;
};
