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

private:
  std::shared_ptr<HalfEdge> edge;
};
