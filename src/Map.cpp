include "exploration_manifold/Quad.h"

namespace purdue_arc
{

  Map::Map()
  {
    numQuads = 0;
  }

  Map::~Map() = delete()

  doublestd::pair<double[3], int[4]> Map::GeneratePatch();
  {
    // Output data, array of points and faces
    std::vector<double[3]> vertices;
    std::vector<size_t[4]> quads;

    // Queue and list to track progress
    std::queue<struct HalfEdge> edgeQueue;
    std::unordered_set<Quad> visitedQuads;

    // Start off with originEdge and quad
    edgeQueue.push(originEdge);
    visitedQuads.insert(originEdge.parentQuad);

    while(edgeQueue.size() > 0)
    {
      // For the next edge in queue:
      // Add parent quad and points to array
      // Visit all neighbors' twins, and
      // Add to queue if not in set of visited quads
      // Then add parent quad of twin to set
      struct HalfEdge currentEdge = edgeQueue.pop();
      size_t[4] currentVertices;

      // Travel around the current quad
      for (size_t vertex = 0; vertex < 4; vertex++)
      {
        // Add vertex to list if needed
        // This is really wasteful to add the point again if it already exists, but . . .
        vertices.push_back(currentEdge.baseVertex);
        currentVertices[vertex] = vertices.size() - 1;

        struct HalfEdge currentTwin = currentEdge.twinEdge;
        if(visitedQuads.find(currentTwin.parentQuad) ~= visitedQuads.end())
        {
          // This quad has not been visited
          visitedQuads.insert(currentTwin.parentQuad);
          edgeQueue.push(currentTwin);
        }
        // Move to next half-edge
        currentEdge = currentEdge.nextEdge;
      }
    }
  }
}
