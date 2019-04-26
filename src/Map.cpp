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

  int quadrant_x_dir [4] = {1, -1, -1, 1};
  int quadrant_y_dir [4] = {1, 1, -1, -1};

  for(size_t quadrant = 0; quadrant < 4; ++quadrant) {
    // Set the quadrant variables
    int x_dir = quadrant_x_dir[quadrant];
    int y_dir = quadrant_y_dir[quadrant];

    // Make the edges
    std::shared_ptr<HalfEdge::Vertex> pt1 (new HalfEdge::Vertex(x_dir*v_x[0], x_dir*v_x[1], x_dir*v_x[2]));
    std::shared_ptr<HalfEdge::Vertex> pt2 (new HalfEdge::Vertex(x_dir*v_x[0], y_dir*v_y[1], x_dir*v_x[2] + y_dir*v_y[2]));
    std::shared_ptr<HalfEdge::Vertex> pt3 (new HalfEdge::Vertex(y_dir*v_y[0], y_dir*v_y[1], y_dir*v_y[2]));

    // loop around the quad, keeping a link to the last one.
    activeEdge = std::shared_ptr<HalfEdge> (new HalfEdge(pt1, quad, activeEdge, nullptr, nullptr));
    activeEdge = std::shared_ptr<HalfEdge> (new HalfEdge(pt2, quad, activeEdge, nullptr, nullptr));
    activeEdge = std::shared_ptr<HalfEdge> (new HalfEdge(pt3, quad, activeEdge, nullptr, nullptr));

    // Make a complete backwards link
    (activeEdge->previous()->previous()->previous())->setPrevious(activeEdge);

    std::cout << "Creating Geometry (" << quadrant << ")" << std::endl;

    // Link them forwards
    HalfEdge::iterator itr = activeEdge->begin();
    do {
      itr->setNext(itr->previous()->previous()->previous());
      --itr;
      std::cout << "Forward linking" << std::endl;
    } while(itr != activeEdge->begin());

    if (quadrant < 3) {
      // Create new geometry for the next iteration
      std::cout << "Twin Linking" << std::endl;
      quad = std::shared_ptr<HalfEdge::Quad> (new HalfEdge::Quad(normalAngle_rad, 0.0, 1.0));
      std::shared_ptr<HalfEdge> newEdge (new HalfEdge(originVertex, quad, nullptr, activeEdge, nullptr));
      activeEdge->setTwin(newEdge);
      activeEdge =  std::shared_ptr<HalfEdge> (newEdge);
    }
  }
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
    std::cout << "Traveling geometry" << std::endl;
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
