namespace purdue_arc
{
    struct HalfEdge
    {
      double baseVertex[3];
      Quad *parentQuad;
      struct HalfEdge *prevEdge;
      struct HalfEdge *twinEdge;
      struct HalfEdge *nextEdge;
    };

class Map {
public:
    Map();
    ~Map();

    std::pair<double[3], int[4]> GeneratePatch();

private:
  struct HalfEdge originEdge;


};
}
