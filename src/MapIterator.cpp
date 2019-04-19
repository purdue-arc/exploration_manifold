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

Map.mapHalfEdge & MapIterator::operator*(){
  return *edge;
}
