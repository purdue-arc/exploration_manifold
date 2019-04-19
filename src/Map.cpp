#include "exploration_manifold/Map.h"

Map::Map()
{
  numQuads = 0;
  originEdge = NULL
}

Map::~Map() = default;

std::pair<std::array<double[3]>, std::array<size_t[4]>> Map::GeneratePatch()
{
  // Queue of discovered edges to visit
  std::queue<mapHalfEdge *> edgeQueue;

  // Set of quads keys that we have visited or have queued
  std::unordered_set<size_t> visitedQuads;

  // Vector of quad's vertices' keys that we have visited
  std::vector<size_t[4]> quadCornerKeys;

  // map of vertices we have visited and pointer to vertex struct
  std::unordered_map<size_t, mapVertex *> vertexMap;

  // Start off with originEdge and its parent
  edgeQueue.push(originEdgePt);
  visitedQuads.insert(*originEdgePt.parentQuad.key);

  while(not edgeQueue.empty())
  {
    HalfEdge * currentEdgePt = *edgeQueue.front();
    edgeQueue.pop();
    size_t[4] currentCorners;

    // Travel around the current quad
    for (size_t jumps = 0; jumps < 4; jumps++)
    {
      // The base vertex of the current half-edge
      Vertex currentVertex = currentEdge.baseVertex;

      // Add vertex to list of vertices if needed
      vertexMap.insert(std::pair<size_t, Vertex *>(currentVertex.key, &currentVertex))

      // Add vertex's key to list of quad's vertices' keys
      currentCorners[jumps] = currentVertex.key;

      // Check if we have visited the twin
      HalfEdge currentTwin = currentEdge.twinEdge;
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
  // Create a vector of the vertice's positions and sort by key
  std::vector<Vertex *> vertexVector (vertexMap.begin(), vertexMap.end());
  std::sort (vertexVector.begin(), vertexVector.end(),
    [](Vertex * a, Vertex * b)
    {
      return a.key < b.key;
    });

  // Create a vector of indices into the above vector for each of the quads
  std::vector<size_t[4]> patchFaces;
  patchFaces.reserve(vertexVector.size());
  for(auto it = quadCornerVector.begin(); it != quadCornerVector.end(); ++it)
  {
    size_t[4] currentCorners;
    for (size_t jumps = 0; jumps < 4; jumps++)
    {
      currentCorners[jump] = std::lower_bound(vertexVector.begin(), vertexVector.end(), *it[jumps]) - quadCornerVector.begin();
    }
    patchFaces.push_back(currentCorners);
  }


  //quadCornerVector
  //vertexMap
}

iterator Map::begin(){
  return iterator(firstEdge);
}

iterator Map::end(){
  return iterator(lastEdge);
}
