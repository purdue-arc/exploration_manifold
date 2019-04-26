#include "exploration_manifold/HalfEdge.h"

HalfEdge::HalfEdge(std::shared_ptr<Vertex> base, std::shared_ptr<Quad> parent, std::shared_ptr<HalfEdge> prev, std::shared_ptr<HalfEdge> twin, std::shared_ptr<HalfEdge> next){
  baseVertex = std::shared_ptr<Vertex> (base);
  parentQuad = std::shared_ptr<Quad> (parent);
  prevEdge = std::shared_ptr<HalfEdge> (prev);
  twinEdge = std::shared_ptr<HalfEdge> (twin);
  nextEdge = std::shared_ptr<HalfEdge> (next);
}

HalfEdge::~HalfEdge() = default;

std::shared_ptr<HalfEdge> HalfEdge::next(){
  return std::shared_ptr<HalfEdge> (nextEdge);
}

std::shared_ptr<HalfEdge> HalfEdge::previous(){
  return std::shared_ptr<HalfEdge> (prevEdge);
}

std::shared_ptr<HalfEdge> HalfEdge::twin(){
  return std::shared_ptr<HalfEdge> (twinEdge);
}

std::shared_ptr<HalfEdge::Quad> HalfEdge::parent(){
  return std::shared_ptr<HalfEdge::Quad> (parentQuad);
}

std::array<double, 3> HalfEdge::vertexLocation(){
  std::array<double, 3> location;
  location[0] = baseVertex->position_x;
  location[1] = baseVertex->position_y;
  location[2] = baseVertex->position_z;
  return location;
}

void HalfEdge::setNext(std::shared_ptr<HalfEdge> next){
  nextEdge = next;
}

void HalfEdge::setPrevious(std::shared_ptr<HalfEdge> prev){
  prevEdge = prev;
}

void HalfEdge::setTwin(std::shared_ptr<HalfEdge> twin){
  twinEdge = twin;
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
  normalVector[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
  normalVector[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
  normalVector[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
  return normalVector;
}

std::array<double, 3> HalfEdge::vector(){
  std::array<double, 3> edgeVector;
  edgeVector[0] = nextEdge->baseVertex->position_x - baseVertex->position_x;
  edgeVector[1] = nextEdge->baseVertex->position_y - baseVertex->position_y;
  edgeVector[2] = nextEdge->baseVertex->position_z - baseVertex->position_z;
  return edgeVector;
}

HalfEdge::iterator HalfEdge::begin(){
  return iterator(this);
}
