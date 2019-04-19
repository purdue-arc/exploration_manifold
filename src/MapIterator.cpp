#include "exploration_manifold/MapIterator.h"
#include "exploration_manifold/Map.h"

MapIterator::MapIterator(struct Map.mapHalfEdge * edge){
  this->edge = edge;
}

MapIterator::~MapIterator() = default;

MapIterator & MapIterator::operator++(){
  edge = edge->nextEdge;
  return *this;
}

MapIterator MapIterator::operator++(int){
  MapIterator clone(*this);
  edge = edge->nextEdge;
  return clone;
}

MapIterator & MapIterator::operator--(){
  edge = edge->prevEdge;
  return *this;
}

MapIteratore MapIterator::operator--(int){
  MapIterator clone(*this);
  edge = edge->prevEdge;
  return clone;
}

const Map.mapHalfEdge & MapIterator::operator*(){
  return const *edge;
}


// MapIterator & next();
// MapIterator & next(int steps);
// MapIterator & previous();
// MapIterator & previous(int steps);
//
// bool hasTwin();
// MapIterator & twin();
//
// double [3] vector();
//
// double [3] normal();
// double normalAngle();
// double variance();
// double certainty();
