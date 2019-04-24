#include <memory>
// forward declare the HalfEdge class
class HalfEdge;

class HalfEdgeIterator {
public:
  HalfEdgeIterator(std::shared_ptr<HalfEdge> edge);
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
  std::shared_ptr<HalfEdge> edge;
};
