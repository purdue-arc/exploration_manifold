#include "exploration_manifold/HalfEdge.h"
#include "exploration_manifold/HalfEdgeIterator.h"

HalfEdge::HalfEdge(shared_ptr<Vertex> base, shared_ptr<Quad> parent, shared_ptr<HalfEdge> prev, shared_ptr<HalfEdge> twin, shared_ptr<HalfEdge> next){
  this->baseVertex = base;
  this->parentQuad = parent;
  this->prevEdge = prev;
  this->twinEdge = twin;
  this->nextEdge = next;
}

HalfEdge::~HalfEdge() = default;

HalfEdge & HalfEdge::next(){
  return *nextEdge;
}

HalfEdge & HalfEdge::previous(){
  return *prevEdge;
}

HalfEdge & HalfEdge::twin(){
  return *twinEdge;
}

double HalfEdge::parentNormalAngle(){
  return parentQuad->normalAngle_rad;
}

double HalfEdge::parentVariance(){
  return parentQuad->variance;
}

double HalfEdge::parentCertainty(){
  return parentQuad->certainty;
}

bool HalfEdge::hasTwin(){
  return bool(twinEdge);
}

std::array<double, 3> HalfEdge::parentNormal(){
  const std::array<double, 3> & vector1 = this->vector();
  const std::array<double, 3> & vector2 = nextEdge->vector();
  std::array<double, 3> normalVector;
  normalVector.at(0) = vector1.at(1) * vector2.at(2) - vector1.at(2) * vector2.at(1);
  normalVector.at(1) = vector1.at(2) * vector2.at(0) - vector1.at(0) * vector2.at(2);
  normalVector.at(2) = vector1.at(0) * vector2.at(1) - vector1.at(1) * vector2.at(0);
  return normalVector;
}

std::array<double, 3> HalfEdge::vector(){
  std::array<double, 3> edgeVector;
  edgeVector.at(0) = nextEdge->baseVertex->position_x - baseVertex->position_x;
  edgeVector.at(1) = nextEdge->baseVertex->position_y - baseVertex->position_y;
  edgeVector.at(2) = nextEdge->baseVertex->position_z - baseVertex->position_z;
  return edgeVector;
}

HalfEdgeIterator HalfEdge::iterator(){
  return HalfEdgeIterator(*this);
}
