#include "exploration_manifold/HalfEdgeIterator.h"

#ifndef HALFEDGE_H
#define HALFEDGE_H
#include "exploration_manifold/HalfEdge.h"
#endif

HalfEdgeIterator::HalfEdgeIterator(std::shared_ptr<HalfEdge> edge){
  this->edge = edge;
}

HalfEdgeIterator::~HalfEdgeIterator() = default;

HalfEdgeIterator & HalfEdgeIterator::operator++(){
  edge = std::shared_ptr<HalfEdge> (&(edge->next()));
  return *this;
}

HalfEdgeIterator HalfEdgeIterator::operator++(int){
  HalfEdgeIterator clone(edge);
  edge = std::shared_ptr<HalfEdge> (&(edge->next()));
  return clone;
}

HalfEdgeIterator & HalfEdgeIterator::operator--(){
  edge = std::shared_ptr<HalfEdge> (&(edge->previous()));
  return *this;
}

HalfEdgeIterator HalfEdgeIterator::operator--(int){
  HalfEdgeIterator clone(edge);
  edge = std::shared_ptr<HalfEdge> (&(edge->previous()));
  return clone;
}

HalfEdge & HalfEdgeIterator::operator*(){
  return *edge;
}
