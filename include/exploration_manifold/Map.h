namespace purdue_arc
{
    struct HalfEdge
    {
      struct Vertex * baseVertex;
      struct Quad * parentQuad;

      struct HalfEdge * prevEdge;
      struct HalfEdge * twinEdge;
      struct HalfEdge * nextEdge;

      size_t key;
    };

    struct Vertex
    {
      double position_x;
      double position_y;
      double position_z;

      size_t key;
    };

    struct Quad
    {
      double normal_x;
      double normal_y;
      double normal_z;

      double variance;
      double certainty;

      size_t key;
    }

class Map {
public:
    Map();
    ~Map();

    std::pair<std::array<double[3]>, std::array<size_t[4]>> Map::GeneratePatch();;

private:
  struct HalfEdge originEdge;
  unsigned int numQuads;


};
}
