#include "exploration_manifold/HalfEdgeIterator.h"

HalfEdgeIterator::HalfEdgeIterator(HalfEdge & edge){
  this->edge = edge;
}

HalfEdgeIterator::~HalfEdgeIterator() = default;

HalfEdgeIterator & HalfEdgeIterator::operator++(){
  edge = edge.next();
  return *this;
}

HalfEdgeIterator HalfEdgeIterator::operator++(int){
  HalfEdgeIterator clone(edge);
  edge = edge.next();
  return clone;
}

HalfEdgeIterator & HalfEdgeIterator::operator--(){
  edge = edge.previous();
  return *this;
}

HalfEdgeIterator HalfEdgeIterator::operator--(int){
  HalfEdgeIterator clone(edge);
  edge = edge.previous();
  return clone;
}

HalfEdgeIterator & HalfEdgeIterator::operator*(){
  return *edge;
}
