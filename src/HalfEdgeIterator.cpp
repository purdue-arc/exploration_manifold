//#include "exploration_manifold/HalfEdgeIterator.h"
#include "exploration_manifold/HalfEdge.h"

HalfEdgeIterator::HalfEdgeIterator(HalfEdge * edge)
{
  this->edge = edge;
}

HalfEdgeIterator::~HalfEdgeIterator() = default;

HalfEdgeIterator & HalfEdgeIterator::operator++(){
  edge = edge->next();
  return *this;
}

HalfEdgeIterator HalfEdgeIterator::operator++(int){
  HalfEdgeIterator clone(edge);
  edge = edge->next();
  return clone;
}

HalfEdgeIterator & HalfEdgeIterator::operator--(){
  edge = edge->previous();
  return *this;
}

HalfEdgeIterator HalfEdgeIterator::operator--(int){
  HalfEdgeIterator clone(edge);
  edge = edge->previous();
  return clone;
}

HalfEdge & HalfEdgeIterator::operator*(){
  return *edge;
}

HalfEdge * HalfEdgeIterator::operator->(){
  return edge;
}

bool HalfEdgeIterator::operator!=(const HalfEdgeIterator & other){
  return this->edge != other.edge;
}
