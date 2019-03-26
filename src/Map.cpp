include "exploration_manifold/Quad.h"

namespace purdue_arc
{

  Map::Map()
  {
    numQuads = 0;
  }

  Map::~Map() = delete();

  std::pair<std::array<double[3]>, std::array<size_t[4]>> Map::GeneratePatch()
  {
    // Queue of discovered edges to visit
    std::queue<struct HalfEdge *> edgeQueue;

    // Set of quads keys that we have visited or have queued
    std::unordered_set<size_t> visitedQuads;

    // Vector of quad's vertices' keys that we have visited
    std::vector<size_t[4]> quadCornerVector;
    
    // map of vertices we have visited and pointer to vertex struct
    std::unordered_map<size_t, struct Vertex *> vertexMap;

    // Start off with originEdge and its parent
    edgeQueue.push(&originEdge);
    visitedQuads.insert(originEdge.parentQuad.key);

    while(edgeQueue.size() > 0)
    {
      struct HalfEdge currentEdge = edgeQueue.pop();
      size_t[4] currentCorners;

      // Travel around the current quad
      for (size_t jumps = 0; jumps < 4; jumps++)
      {
        // The base vertex of the current half-edge
        struct Vertex currentVertex = currentEdge.baseVertex;

        // Add vertex to list of vertices if needed
        vertices.insert(std::pair<size_t, struct Vertex *>(currentVertex.key, &currentVertex))

        // Add vertex's key to list of quad's vertices' keys
        currentCorners[jumps] = currentVertex.key;

        // Check if we have visited the twin
        struct HalfEdge currentTwin = currentEdge.twinEdge;
        if(visitedQuads.find(currentTwin.parentQuad.key) ~= visitedQuads.end())
        {
          // This quad has not been visited
          visitedQuads.insert(currentTwin.parentQuad.key);
          edgeQueue.push(&currentTwin);
        }

        // Move to next half-edge
        currentEdge = currentEdge.nextEdge;
      }

      // Add vertex data for quad to vector
      quadCornerVector.insert(currentCorners);
    }

    // queue is empty, meaning we have visited all half edges, quads, and vertices
    //quadCornerVector
    //vertexMap
  }
}
