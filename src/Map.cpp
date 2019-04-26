#include "exploration_manifold/Map.h"
#include <math.h>
#include <iostream>
#include <queue>
#include <unordered_set>

Map::Map(double v_x [3], double v_y [3])
{
  numQuads = 0;

  std::shared_ptr<HalfEdge::Vertex> originVertex (new HalfEdge::Vertex(0.0, 0.0, 0.0));

  const double normalAngle_rad = acos(v_x[0] * v_y[1] - v_x[1] * v_y[0]);
  std::shared_ptr<HalfEdge::Quad> quad (new HalfEdge::Quad(normalAngle_rad, 0.0, 1.0));

  originEdge = std::shared_ptr<HalfEdge> (new HalfEdge(originVertex, quad, nullptr, nullptr, nullptr));
  activeEdge = std::shared_ptr<HalfEdge> (originEdge);

  // for(int8_t x_dir = -1; x_dir < 2; x_dir += 2)
  // {
  //   for(int8_t y_dir = -1; y_dir < 2; y_dir += 2)
  //   {
      std::shared_ptr<HalfEdge::Vertex> pt1 (new HalfEdge::Vertex(v_x[0], v_x[1], v_x[2]));
      std::shared_ptr<HalfEdge::Vertex> pt2 (new HalfEdge::Vertex(v_x[0], v_y[1], v_x[2] + v_y[2]));
      std::shared_ptr<HalfEdge::Vertex> pt3 (new HalfEdge::Vertex(v_y[0], v_y[1], v_y[2]));

      // loop around the quad, keeping a link to the last one.
      activeEdge = std::shared_ptr<HalfEdge> (new HalfEdge(pt1, quad, activeEdge, nullptr, nullptr));
      activeEdge = std::shared_ptr<HalfEdge> (new HalfEdge(pt2, quad, activeEdge, nullptr, nullptr));
      activeEdge = std::shared_ptr<HalfEdge> (new HalfEdge(pt3, quad, activeEdge, nullptr, nullptr));

      // Make a complete backwards link
      (activeEdge->previous()->previous()->previous())->setPrevious(activeEdge);

      std::cout << "Breakpoint 1" << std::endl;

      // Link them forwards
      HalfEdge::iterator itr = activeEdge->begin();
      do {
        itr->setNext(itr->previous()->previous()->previous());
        --itr;
        std::cout << "Breakpoint loop" << std::endl;
      } while(itr != activeEdge->begin());

      // Create an active edge for the next loop to use
  //   }
  // }
}

Map::~Map() = default;

std::vector<std::array<std::array<double, 3>, 4>> Map::exportGeometry(){
  // Queue of discovered edges we have yet to visit
  std::queue<HalfEdge*> edgeQueue;

  // Set of quads that we have already visited
  std::unordered_set<HalfEdge::Quad*> visitedQuads;

  // Polygons / geometry that we have visited
  std::vector<std::array<std::array<double, 3>, 4>> geometryVector;

  // Start off with originEdge and its parent
  edgeQueue.push(originEdge.get());
  visitedQuads.insert(originEdge->parent().get());

  while(!edgeQueue.empty())
  {
    HalfEdge * currentEdge = edgeQueue.front();
    edgeQueue.pop();

    std::array<std::array<double, 3>, 4> currentCorners;

    // Travel around the current quad
    for (size_t i = 0; i < 4; i++) {
      // The base vertex of the current half-edge
      currentCorners[i] = currentEdge->vertexLocation();

      // Check if we have visited the twin
      if(currentEdge->hasTwin())
      {
        HalfEdge * currentTwin = currentEdge->twin().get();
        if(visitedQuads.find(currentTwin->parent().get()) != visitedQuads.end())
        {
          // This quad has not been visited
          visitedQuads.insert(currentTwin->parent().get());
          edgeQueue.push(currentTwin);
        }
      }
      // Move to next half-edge
      currentEdge = currentEdge->next().get();
    }

    // Add vertex data for quad to vector
    geometryVector.push_back(currentCorners);
  }

  return geometryVector;
}
