#include "exploration_manifold/HalfEdgeMap.h"

class MapIterator {
public:
  MapIterator(mapHalfEdge * edge);
  ~MapIterator();

  // Standard operations
  MapIterator & operator++();
  MapIterator operator++(int);
  MapIterator & operator--();
  MapIterator operator--(int);
  const mapHalfEdge & operator*();

  // Custom operations
  MapIterator & next();
  MapIterator & next(int steps);
  MapIterator & previous();
  MapIterator & previous(int steps);

  bool hasTwin();
  MapIterator & twin();

  double [3] vector();

  double [3] normal();
  double normalAngle();
  double variance();
  double certainty();

private:
  struct Map.mapHalfEdge * edge;   // edge that we are pointing to
};
