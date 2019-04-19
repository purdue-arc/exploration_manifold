class MapIterator {
public:
  MapIterator(struct Map.mapHalfEdge * edge);
  ~MapIterator();
private:
  struct Map.mapHalfEdge * edge;   // edge that we are pointing to

  // Incrementing
  MapIterator & operator++();
  MapIterator operator++(int);

  // Decrementing
  MapIterator & operator--();
  MapIterator operator--(int);

  // Dereference
  struct Map.mapHalfEdge & operator*();
};
