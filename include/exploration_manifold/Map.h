namespace purdue_arc
{
    struct HalfEdge
    {
      struct Vertex *baseVertex;
      struct Quad *parentQuad;
      struct HalfEdge *prevEdge;
      struct HalfEdge *twinEdge;
      struct HalfEdge *nextEdge;
      unsigned int key;
    };

    struct Vertex
    {
      double position_x;
      double position_y;
      double position_z;
      unsigned int key;
    };

    struct Quad
    {
      double normal_x;
      double normal_y;
      double normal_z;
      double variance;
      double certainty;
      unsigned int key;
    }

class Map {
public:
    Map();
    ~Map();

    std::pair<double[3], int[4]> GeneratePatch();

private:
  struct HalfEdge originEdge;
  unsigned int numQuads;


};
}
